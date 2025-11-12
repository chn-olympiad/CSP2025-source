#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,q,ans,cnt;
string s1,s2,s3,s4,s5,s6,s7;
map<string,int> ms;
map<int,string> sm;
int p[100001];
bool la[1000001];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld%lld",&n,&q);
	//if(n <= 1000 && q <= 1000 && q != 1){
		for(int i = 1;i <= n;i++){
			cin>>s1>>s2;
			p[i] = s1.length() - 1;
			la[p[i]] = 1;
			ms[s1] = i;
			sm[i] = s2;
		}
		bool flag;
		int be,en,l;
		for(int v = 1;v <= q;v++){
			ans = 0;
			cin>>s1>>s2;
			flag = 0;
			l = s1.length() - 1;
			for(int i = 0;i <= l;i++){
				if(s1[i] != s2[i]){
					if(flag == 0){
						flag = 1;
						be = i;
					}
					en = i;
				}
			}
			//cout<<be<<" "<<en<<endl;
			if(en - be == l){
				printf("0\n");
				continue;
			}
			for(int i = be;i >= 0;i--){
				s3=s7;
				s5=s7;
				s4 = "a";
				for(int j = i;j < en;j++){
					s3 = s3 + s4;
					s3[j-i] = s1[j];
					s5 = s5 + s4;
					s5[j - i] = s2[j];
				}
				for(int j = en;j <= l;j++){
					s3 = s3 + s4;
					s3[j - i] = s1[j];
					s5 = s5 + s4;
					s5[j - i] = s2[j];
					//cout<<s3<<" "<<s5<<" "<<ms[s3]<<" "<<sm[ms[s3]]<<endl;
					if(la[j - i]){
						s6 = sm[ms[s3]];
						if(s6 == s5){
							ans++;
						}
					}
				}
			}
			printf("%lld\n",ans);
		}
	//}
	
	
	return 0;
}
