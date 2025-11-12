#include<iostream>
#include<vector>
using namespace std;
int a[200005];
vector<pair<int,int> > e;//first:l,second:r
vector<pair<int,bool> > book;//first:l,second:book
int max_cnt=0;
int max_sum;
void dfs(int step,int cnt){
	if(cnt>max_cnt) max_cnt=cnt;
	if(step>max_sum) return;
	for(int i=0;i<max_sum;i++){
		if(book[i].second==false){
			int flag=true;
			for(int j=0;j<max_sum;j++){
				if(book[j].second==true&&e[j].second>=e[i].first){
					flag=false;
					break;
				}
			}
			if(flag){
				book[i].second=true;
				dfs(step+1,cnt+1);
				book[i].second=false;
			}
		}
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int xor_sum=a[i];
		for(int j=i+1;j<=n+1;j++){
			if(xor_sum==k){
				e.push_back({i,j-1});
				book.push_back({i,false});
				max_sum++;
				break;
			}
			xor_sum=xor_sum^a[j];
		}
	}
	dfs(1,0);
	cout<<max_cnt;
	return 0;
}

