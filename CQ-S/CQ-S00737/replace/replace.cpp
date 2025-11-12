#include <bits/stdc++.h>
using namespace std;
 

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	long long n,q;
	scanf("%lld%lld",&n,&q);
	//输入元组和问题 
	string s1[5000005],s2[5000005];
	string t1[5000000005],t2[5000000005];
	for(long long i=1;i<=n;i++) cin>>s1[i]>>s2[i];
	for(long long i=1;i<=q;i++) cin>>t1[i]>>t2[i];
	
	string S[5000000005];
	string x,y,z;
	string tlx,tly,tlz;
	int ans=0;
	int all[5000000005];
	
	//拆分问题中的字符串 
	for(long long i=1;i<=q;i++){
		
		for(long long j=1;j<=t1[i].length();j++){
			S[j]=t1[i][j];
		}
		
		//（对x,y,z进行遍历处理，可以得到不同的字符串组合） 
		//=======================================================================================
		for(long long a=0;a<=q;i++){
			x += S[a];
			for(long long b=3;b<=q+1;b++){
				z += S[a];
				for(long long k=a;k<=b-1;k++) y+= S[k];
				for(long long l=1;l<=n;l++){
					
					//(判断x,y,z是否有与二元组中有合适的) 
					//---------------------------------------------------------------------------
					if(x==s1[i]){
						tlx=x;
						x=s2[a];
						for(long long o=1;o<=q;o++){
							if(x+y+z==t2[a]){
								ans++;
								continue;
							}
						}
					} 
					if(y==s1[a]){
						tly=y;
						y=s2[a];
						for(long long o=1;o<=q;o++){
							if(x+y+z==t2[a]||tlx+y+z==t2[a]){
								ans++;
								continue;
							}
						}
					}
					if(z==s1[a]){
						tlz=z;
						z=s2[a];
						for(long long o=1;o<=q;o++){
							if(x+y+z==t2[a]||tlx+y+z==t2[a]||x+tly+z==t2[a]||tlx+tly+z==t2[a]){
								ans++;
								continue;
							}
						}
					}
					//---------------------------------------------------------------------------
				}
			}
		}
		//=======================================================================================
		all[i]=ans;
		
	}
	
	for(int i=1;i<=q;i++) printf("%d",&all[i]);
	
	return 0;
} 
