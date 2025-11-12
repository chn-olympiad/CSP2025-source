#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
map<int,pair<int,int>>mp;
pair<int,int>a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int cnt=n*m;
	for(int i=1;i<=m;i++){
		if(i%2!=0){
			for(int j=1;j<=n;j++){
				mp[cnt--]=make_pair(i,j);
			}
		}else{
			for(int j=n;j>0;j--){
				mp[cnt--]=make_pair(i,j);
			}
		}
	}
	for(int i=1;i<=n*m;i++){
		cin>>a[i].first;
		a[i].second=i;
	}
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a[i].second==1){
			cout<<mp[i].first<<" "<<mp[i].second;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}