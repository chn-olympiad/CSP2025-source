#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>

using namespace std;

int a[105];
bool cmp(int x,int y) {
	return x>y;
}
int n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	} 
	int t=a[1];
	sort(a+1,a+n*m+1,cmp);
	int pp=0,cnt=0;
	for(int i=1;i<=n*m;i++)if(a[i]==t)pp=i;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				cnt++;
				if(cnt==pp){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}else{
			for(int j=n;j>=1;j--){
				cnt++;
				if(cnt==pp){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
} 
