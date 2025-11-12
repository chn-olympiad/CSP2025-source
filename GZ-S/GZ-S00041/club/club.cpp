//GZ-S00041 北京师范大学贵阳附属中学 冷东来
#include <bits/stdc++.h>
using namespace std;
struct stu{
	int ma;
	int ch1;
};
vector<stu> arr(100005);
bool compare(int a,int b){
	return (arr[a].ch1)<(arr[b].ch1);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> a1,b1,c1;
		arr.clear();
		long long ans=0;
		for(int i=0;i<n;i++){
			int a,b,c;
			cin>>a>>b>>c;
			if(a>=b&&b>=c){
				a1.push_back(i);
				ans+=a;
				arr[i].ma=a;
				arr[i].ch1=a-b;
			}else if(a>=c&&c>=b){
				ans+=a;
				a1.push_back(i);
				arr[i].ma=a;
				arr[i].ch1=a-c;
			}else if(b>=a&&a>=c){
				ans+=b;
				b1.push_back(i);
				arr[i].ma=b;
				arr[i].ch1=b-a;
			}else if(b>=c&&c>=a){
				ans+=b;
				b1.push_back(i);
				arr[i].ma=b;
				arr[i].ch1=b-c;
			}else if(c>=a&&a>=b){
				ans+=c;
				c1.push_back(i);
				arr[i].ma=c;
				arr[i].ch1=c-a;
			}else if(c>=b&&b>=a){
				ans+=c;
				c1.push_back(i);
				arr[i].ma=c;
				arr[i].ch1=c-b;
			}
		}
		int limit=n/2;
		int asize=a1.size();
		if(asize>limit){
			//cout<<"a overload"<<endl;
			sort(a1.begin(),a1.end(),compare);
			for(int i=0;asize>limit;i++){
				ans-=arr[a1[i]].ch1;
				asize--;
			}
		} 
		int bsize=b1.size();
		if(bsize>limit){
			//cout<<"b overload"<<endl;
			sort(b1.begin(),b1.end(),compare);
			for(int i=0;bsize>limit;i++){
				ans-=arr[b1[i]].ch1;
				bsize--;
			}
		}
		int csize=c1.size();
		if(csize>limit){
			//cout<<"c overload"<<endl;
			sort(c1.begin(),c1.end(),compare);
			for(int i=0;csize>limit;i++){
				ans-=arr[c1[i]].ch1;
				csize--;
			}
		}
		cout<<ans;
		if(t!=0){
			cout<<endl;
		}
	}
	return 0;
} 
