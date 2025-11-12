#include<bits/stdc++.h>
using namespace std;
int a[5005],n;
long long idea=0;
void find(int x,int num,int id,int ma){
	if(id>=n) return ;
	if(x>2*ma&&num>=3){
		idea++;
		return ;
	}
	for(int i=0;i<id;i++){
		ma=max(ma,a[i]);
		find(x+a[i],num+1,id+1,ma);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		int x=a[i],ma=a[i];
		find(x,1,i+1,ma);
	}
	cout<<(idea+1)%998224353;
	return 0;
}
