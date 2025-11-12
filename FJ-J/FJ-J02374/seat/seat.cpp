#include<bits/stdc++.h>
using namespace std;
int n,m,r;
int a[105],b[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int mem=n*m;
	cin>>r;
	a[1]=r;
	for(int i=2;i<=mem;i++){
		cin>>a[i];
	}
	sort(a+1,a+mem+1);
	int i;
	int j=0;
	for(int i=mem;i>=1;i--){
		j++;
		b[j]=a[i];
	}
	for(i=1;i<=mem;i++){
		if(b[i]==r)
			break;
	}
	if(i<=n){
		cout<<1<<" "<<i;
	}
	else{
		int li=i/n;
		li%=2;//0:zhengshu,1:jishu
		int lo=i%n;
		if(!lo){
			if(li){
				cout<<i/n<<" "<<1;
			}
			else{
				cout<<(i/n)+1<<" "<<n;
			}
		}
		else{
			if(!li){
				cout<<(i/n)+1<<" "<<lo;
			}
			else{
				cout<<(i/n)+1<<" "<<n+1-lo;
			}
		}
		
	}
	return 0;
}

