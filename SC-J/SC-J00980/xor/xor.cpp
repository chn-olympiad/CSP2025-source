#include<bits/stdc++.h>
using namespace std;
int n,k,l=0,x=1,a[1000010],b[1000][500010];
bool pd(){
	int sum=b[x][1];
	for(int i=2;i<=l;i++){
		sum=sum ^ b[x][i];
	}
	if(sum==k)return true;
	else return false;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=0,sum=0;
	for(int i=1;i<=n;i++){
		l=1,x=1,sum=0;
		for(int j=1;j<i;j++){
			l++;
			b[x][l]=a[j];
			if(pd()){
			/*	for(int i=1;i<=l;i++){
					cout<<b[x][i]<<' '; 
				}
				cout<<endl;*/
				x++;
				sum++;
				l=1;
			}
		}
		l=1,x=1;
		for(int j=i;j<=n;j++){
			l++;
			b[x][l]=a[j];
			if(pd()){
			/*	for(int i=1;i<=l;i++){
					cout<<b[x][i]<<' '; 
				}
				cout<<endl;*/
				sum++;
				x++;
				l=1;
			}
		}
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
} 