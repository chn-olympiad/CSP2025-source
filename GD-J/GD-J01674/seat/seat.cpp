#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	
	int n=0,m=0,c=0,r=0,idx=-1;
	cin>>n>>m; 
	int scr=0;
	cin>>scr;
	vector<int>a(n*m);
	for(int i=1;i<n*m;i++){
		cin>>a[i];
	}
	//降序排序 
	sort(a.begin()+1,a.end(),greater<int>()); 

	for(int i=1;i<n*m;i++){
		//找到第一个比它小的记录位置 
		if(scr>a[i]&&idx==-1){//且为-1没记录过 
			//记录
			idx=i;
		}
	}
	
	//排在最后 
	if(idx==-1)idx=n*m;
	
	//先计算列数 
	c=(idx+n-1)/n;
	
	//行数
	r=idx%n;
	//在末尾 
	if(r==0){
		r+=n;
	}
	//如果是偶数行 
	if(c%2==0)r=n+1-r;

	
	cout<<c<<" "<<r; 
	
	
	return 0;
}
