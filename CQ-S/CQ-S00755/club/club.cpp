#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t;
int n;
struct node{
	int x,y,z;
}a[100005];
vector<int>_1,_2,_3;
bool c1(int s,int t){
	return a[s].x>a[t].x;
}
bool c2(int s,int t){
	return a[s].y>a[t].y;
}
bool c3(int s,int t){
	return a[s].z>a[t].z;
}
int ans;
int _a[100005][5];
int _[100005];
void dfs(int x,int __1,int __2,int __3){
	if(x>n){
		int sum=0;
		for(int i=1;i<=n;i++){
			sum+=_a[i][_[i]];
		}
		ans=max(ans,sum);
		return ;
	}
	if(__1<n/2)_[x]=1;dfs(x+1,__1+1,__2,__3);
	if(__2<n/2)_[x]=2;dfs(x+1,__1,__2+1,__3);
	if(__3<n/2)_[x]=3;dfs(x+1,__1,__2,__3+1);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		ans=0;
		_1.clear();
		_2.clear();
		_3.clear();
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i].x>>a[i].y>>a[i].z,_a[i][1]=a[i].x,_a[i][2]=a[i].y,_a[i][3]=a[i].z;
		if(n<=10){
			dfs(1,0,0,0);
			cout<<ans<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++){
			int mx=max({a[i].x,a[i].y,a[i].z});
			if(mx==a[i].x)_1.push_back(i);
			else if(mx==a[i].y)_2.push_back(i);
			else _3.push_back(i);
		}
		while(1){
			if(_1.size()<=n/2&&_2.size()<=n/2&&_3.size()<=n/2)break;
//			cout<<_1.size()<<" "<<_2.size()<<" "<<_3.size()<<"\n";
			if(_1.size()>n/2){
				sort(_1.begin(),_1.end(),c1);
				for(int i=n/2;i<_1.size();i++){
					if(a[_1[i]].y>a[_1[i]].z)_2.push_back(_1[i]);
					else _3.push_back(_1[i]);
				}
				while(_1.size()>n/2)_1.pop_back();
//				cout<<"In 1st if:"<<_1.size()<<"\n";
			}
			if(_2.size()>n/2){
				sort(_2.begin(),_2.end(),c2);
				for(int i=n/2;i<_2.size();i++){
					if(a[_2[i]].x>a[_2[i]].z)_1.push_back(_2[i]);
					else _3.push_back(_2[i]);
				}
				while(_2.size()>n/2)_2.pop_back();
//				cout<<"In 2nd if:"<<_2.size()<<"\n";
			}
			if(_3.size()>n/2){
				sort(_3.begin(),_3.end(),c3);
				for(int i=n/2;i<_3.size();i++){
					if(a[_3[i]].x>a[_3[i]].y)_1.push_back(_3[i]);
					else _2.push_back(_3[i]);
				}
				while(_3.size()>n/2)_3.pop_back();
//				cout<<"In 3rd if:"<<_3.size()<<"\n";
			}
		}
		for(int i=0;i<_1.size();i++)ans+=a[_1[i]].x;//,cout<<_1[i]<<" "<<a[_1[i]].x<<"\n";cout<<"-\n";
		for(int i=0;i<_2.size();i++)ans+=a[_2[i]].y;//,cout<<_2[i]<<" "<<a[_2[i]].y<<"\n";cout<<"--\n";
		for(int i=0;i<_3.size();i++)ans+=a[_3[i]].z;//,cout<<_3[i]<<" "<<a[_3[i]].z<<"\n";cout<<"---\n";
		cout<<ans<<"\n";
	}
	return 0;
}

/*
╩ф~бл 
*/

