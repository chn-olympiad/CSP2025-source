#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
struct node{
	int a,b,c;
}arr[N];
bool cmp(node x,node y){
	return max(x.a,max(x.b,x.c))>max(y.a,max(y.b,y.c));
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,ans=0;
		cin>>n;
		for(int i=1;i<=n;++i){
			cin>>arr[i].a>>arr[i].b>>arr[i].c;
		}
		sort(arr+1,arr+1+n,cmp);
		vector<node> aa,bb,cc;
		for(int i=1;i<=n;++i){
			if(aa.size()<n/2&&(arr[i].a>arr[i].b||bb.size()>=n/2)&&(arr[i].a>arr[i].c||cc.size()>=n/2)){
				aa.push_back(arr[i]);
				ans+=arr[i].a;
			}else if(bb.size()<n/2&&(arr[i].a<arr[i].b||aa.size()>=n/2)&&(arr[i].b>arr[i].c||cc.size()>=n/2)){
				bb.push_back(arr[i]);
				ans+=arr[i].b;
			}else{
				cc.push_back(arr[i]);
				ans+=arr[i].c;
			}
		}
		node num;
		num.a=num.b=num.c=0;
		while(aa.size()<n/2)aa.push_back(num);
		while(bb.size()<n/2)bb.push_back(num);
		while(cc.size()<n/2)cc.push_back(num);
		for(int i=0;i<aa.size();++i){
			for(int j=0;j<bb.size();++j){
				if(aa[i].b+bb[j].a>aa[i].a+bb[j].b){
					ans+=aa[i].b+bb[j].a-aa[i].a-bb[j].b;
					swap(aa[i],bb[j]);
				}
			}
		}
		for(int i=0;i<aa.size();++i){
			for(int j=0;j<cc.size();++j){
				if(aa[i].c+cc[j].a>aa[i].a+cc[j].c){
					ans+=aa[i].c+cc[j].a-aa[i].a-cc[j].c;
					swap(aa[i],cc[j]);
				}
			}
		}
		for(int i=0;i<bb.size();++i){
			for(int j=0;j<cc.size();++j){
				if(bb[i].c+cc[j].b>bb[i].b+cc[j].c){
					ans+=bb[i].c+cc[j].b-bb[i].b-cc[j].c;
					swap(bb[i],cc[j]);
				}
			}
		}
			for(int i=0;i<aa.size();++i){
			for(int j=0;j<bb.size();++j){
				if(aa[i].b+bb[j].a>aa[i].a+bb[j].b){
					ans+=aa[i].b+bb[j].a-aa[i].a-bb[j].b;
					swap(aa[i],bb[j]);
				}
			}
		}
		for(int i=0;i<aa.size();++i){
			for(int j=0;j<cc.size();++j){
				if(aa[i].c+cc[j].a>aa[i].a+cc[j].c){
					ans+=aa[i].c+cc[j].a-aa[i].a-cc[j].c;
					swap(aa[i],cc[j]);
				}
			}
		}
		for(int i=0;i<bb.size();++i){
			for(int j=0;j<cc.size();++j){
				if(bb[i].c+cc[j].b>bb[i].b+cc[j].c){
					ans+=bb[i].c+cc[j].b-bb[i].b-cc[j].c;
					swap(bb[i],cc[j]);
				}
			}
		}
		cout<<ans<<endl;
		aa.clear();
		bb.clear();
		cc.clear();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
