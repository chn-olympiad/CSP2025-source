#include<bits/stdc++.h>
using namespace std;
int n,m,f;
int a[110],b[110][110];
bool cmp(int t1,int t2){
	return t1>t2;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int f=a[1];
	sort(a+1,a+1+n*m,cmp);
	int i=1,j=1,t=1,s=1;
	b[i][j]=a[i];
	int k=n*m-1;
	while(k!=0){
		if(i==1&&s==1){
			while(i!=n){
				i++;
				t++;
				b[i][j]=a[t];
				k--;
			}
		}else if(i==n){
			s++;
			j++;
			t++;
			b[i][j]=a[t];
			k--;
			while(i!=1){
				i--;
				t++;
				b[i][j]=a[t];
				k--;
			}	
		}else if(i==1&&s>1){
			j++;
			t++;
			b[i][j]=a[t];
			k--;
			while(i!=n){
				i++;
				t++;
				b[i][j]=a[t];
				k--;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==f){
				cout<<j<<" "<<i;
			}
		}
	}
	return 0;
}
