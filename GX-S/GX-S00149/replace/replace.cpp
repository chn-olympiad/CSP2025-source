#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
#define ll long long
struct node{
	string s1,s2;
	int l1,l2;
}a[N];
string x,y;
string s,ss;
int n,m,ans;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i].s1>>a[i].s2;
		a[i].l1 = a[i].s1.size();
		a[i].l2 = a[i].s2.size();
	}
	while(m--){
		cin>>x>>y;
		ans = 0;
		for(int i = 1;i<=n;i++){
			s = x,ss = y;
			//cout<<a[i].s1<<" "<<a[i].s2<<" ";
			//if(s.find(a[i].s1)!=-1){
				s = s.substr(0,s.find(a[i].s1))+a[i].s2+s.substr(s.find(a[i].s1)+a[i].l1,s.size());
				//cout<<s<<" "<<ss<<endl;
			//}
			if(s == ss)ans++;
		}
		//cout<<endl;
		printf("%d\n",ans); 
	}
	
	return 0;
}
