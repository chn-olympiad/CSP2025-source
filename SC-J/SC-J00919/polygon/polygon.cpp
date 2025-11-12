#include<iostream>
using namespace std;
int n,a[5003],s,maxa,c[5003],sum,d[5003];
bool b[5003];
void dfs(int t){
	for(int j=1;j<=n;j++){
		d[j]=0;
	}
	for(int i=1;i<=n;i++){
		d[i]=a[i];
		if(b[i]==0&&i>c[t-1]){
			bool bb;
			for(int j=1;j<i;j++){
				if(a[i]==d[j])bb=1;
			}
			if(bb=0){
				s+=a[i];
				maxa=0;
				maxa=max(maxa,a[i]);
				for(int j=1;j<t;j++){
					maxa=max(maxa,c[j]);
				}
				if(t<3){
					c[t]=i;
					b[i]=1;
					dfs(t+1);
					b[i]=0;
				}
				else if(maxa*2<s){
					sum++;
					c[t]=i;
					if(t!=n){
						b[i]=1;
						dfs(t+1);
						b[i]=0;
					}
					s-=a[i];
				}
			}
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1);
	cout<<sum;
	return 0;
}