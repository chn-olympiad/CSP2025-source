//GZ-S00110 周洵羽 贵阳市第十八中学 
#include<bits/stdc++.h>
using namespace std;
int n,q;
string t_1,t_2;
struct node{
	string a,b;
};
node s[1000005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].b;
	}
	while(q--){
		int ans=0;
		cin>>t_1>>t_2;
		for(int i=1;i<=n;i++){
			string t_11=t_1,t_22=t_2;
			bool t=0;
			int pos_1=t_1.find(s[i].a),pos_2=t_2.find(s[i].b);
			if(pos_1==pos_2 && pos_1!=-1){
				for(int j=pos_1,k=0;k<s[i].b.size();j++,k++){
					t_11[j]=t_22[j]='0';
				}
				if(t_11==t_22) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
