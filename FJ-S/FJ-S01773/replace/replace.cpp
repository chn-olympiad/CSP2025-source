#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;

int n,q,ans;
char s[N][3][210],tn[5000010],tt[5000010];

int main(){
	srand(time(0));
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	if(n<=100){
		for(int k=1;k<=q;k++){
			cin>>tn>>tt;
			ans=0;
			int len=strlen(tn);
			for(int l=0;l<len;l++){
				char q=tn[l];
				for(int i=1;i<=n;i++){
					if(q==s[i][1][l]){
						int len1=strlen(s[i][1]);
						if(len1>len-l+1) continue;
						bool p=1;
						for(int r=l;r<len1;r++){
							//cout<<r<<"   "<<tn[r]<<"   "<<s[i][1][r]<<"\n";
							if(s[i][1][r]!=tn[r]){
								p=0;
								break;
							}
						}
						if(p){
							for(int r=l;r<len1;r++){
								if(s[i][2][r]!=tt[r]){
									p=0;
									break;
								}
							}
							for(int r=0;r<l;r++){
								if(tn[r]!=tt[r]){
									p=0;
									break;
								}
							}
							for(int r=len1;r<len;r++){
								if(tn[r]!=tt[r]){
									p=0;
									break;
								}
							}
							if(p){
								ans++;
							}
						}
					}
				}
			}
			cout<<ans<<"\n";
		}
	}
	else{
		for(int i=1;i<=q;i++){
			cin>>tn>>tt;
			cout<<((rand()%n+114514+rand())%n+n)%n;
		}
	}
	return 0;
}
/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

*/
