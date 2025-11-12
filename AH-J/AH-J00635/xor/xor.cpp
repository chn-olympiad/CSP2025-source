#include<bits/stdc++.h>
using namespace std;
int a[100005];long long int cnt=0;
int wei(int x,int y){
	int ox[25],oy[25],xl=0,yl=0,sum=0;
	memset(ox,0,sizeof(ox));
	memset(oy,0,sizeof(oy));
	while(x!=0){
		ox[++xl]=x%2;
		x/=2;
	}
	while(y!=0){
		oy[++yl]=y%2;
		y/=2;
	}
	int len=max(xl,yl);
	int opm=1;
	for(int i=1;i<=len;i++){
		if(ox[i]!=oy[i]){
			sum+=opm;
		}
		opm*=2;
	}
	return sum;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int i=1,j=0,shang=a[i];
	while(i!=n+1){
		j++;
		if(j==n+1){
			i++;
			j=i;
			shang=a[i];
		}
		if(i==j){
			if(a[i]==k){
				cnt++;
				i++;
			}
		}
		else{
			shang=wei(shang,a[j]);
			if(shang==k){
				i=j;
				cnt++;
				shang=a[i];
			}
		}
	}
	cout<<cnt;
	return 0;
}
