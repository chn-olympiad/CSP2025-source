#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q;
string t_1,t_2;
struct sb{
	string s[3];
	int l,L;
}ex[211111];
bool cmp(sb a,sb b){
	return a.l<b.l;
}
int qian,hou,az;
int ans;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); 
	cout.tie(0); 
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>ex[i].s[1]>>ex[i].s[2];
		if(ex[i].s[1]==ex[i].s[2])continue;
		ex[i].l=ex[i].s[1].size();
		ex[i].L=ex[i].s[1].size();
		int j=0;
		while(ex[i].s[1][j]==ex[i].s[2][j]){
			ex[i].L--;
			j++;
		}
		j=ex[i].s[1].size()-1;
		while(ex[i].s[1][j]==ex[i].s[2][j]){
			ex[i].L--;
			j--;
		}
	}
	sort(ex+1,ex+1+n,cmp);
	for(int i=1;i<=q;i++){
		cin>>t_1>>t_2;
		for(int i=0;i<t_1.size();i++){
			qian=i;
			if(t_1[i]!=t_2[i]){
				break;
			}
		}
		for(int i=t_1.size()-1;i>=0;i--){
			hou=i;
			if(t_1[i]!=t_2[i]){
				break;
			}
		}
		az=hou-qian+1;
		for(int j=1;j<=n;j++){
			if(ex[j].L<az)continue;
//			cout<<ex[j].s[1]<<" "<<ex[j].s[2]<<"\n";
			for(int k=0;k<=qian;k++){
				int qi=0;
				if(t_1[k]==ex[j].s[1][qi]&&t_2[k]==ex[j].s[2][qi]&&k+ex[j].l-1<t_1.size()&&k+ex[j].l-1>=hou){//
//					cout<<"&&& ";
					int falg=0;
					for(int l=1;l<ex[j].l;l++){
						if(t_1[l+k]!=ex[j].s[1][l]||t_2[l+k]!=ex[j].s[2][l]){
							falg=1;
							break;
						}
					}
					if(falg==0){
						ans++;
					}
				}
			}
		}
		cout<<ans<<"\n";
		ans=0;
	}
	return 0;
}
