#include<bits/stdc++.h>
using namespace std;
const int N=2e5+7;
#define ll long long
#define pii pair<int,int> 
#define fir first
#define sec second
#define mkpir make_pair

//void opened(){
//}
string s1[N],s2[N];
int ans;

int main(){
//	opened();
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout); 
	
	int n,q;
	cin>>n>>q;
	
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	
	string str1,str2;
	
	for(int rp=1;rp<=q;rp++){
		cin>>str1>>str2;
		int sz=str1.size();
		ans=0;
		
		int idx1,idx2;
		
		for(int i=sz-1;i>=0;i--){
			if(str1[i]!=str2[i]){
				idx1=i;
				break;
			}
		}
		
		for(int i=0;i<=idx1;i++){
			if(str1[i]!=str2[i]){
				idx2=i;
				break;
			}
		}
		
		for(int i=idx1;i<sz;i++){
			for(int j=1;j<=n;j++){
				int siz=s1[j].size();
				if(siz>i)continue;
				if(i-siz>=idx2)continue;
				bool flag=true;
				for(int k=0;k<siz;k++){
					if(s1[j][siz-k-1]==str1[i-k]&&s2[j][siz-k-1]==str2[i-k]){
						
					}else{
						flag=false;
						break;
					}
				}
				if(flag){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
		
	}
	
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

*/
