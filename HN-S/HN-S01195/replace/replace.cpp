#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,q,len1[N],len2[N],ans[N]; 
string s1,s2,t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		string tt1,tt2;
		cin>>tt1>>tt2;
		len2[i]=tt1.size()+len2[i-1];
		for(int j=len2[i-1];j<len2[i];j++){
			t1[j]=tt1[j-len2[i-1]];
			t2[j]=tt2[j-len2[i-1]];
		}
	}
	for(int i=1;i<=q;i++){
		string ss1,ss2;
		cin>>ss1>>ss2;
		len1[i]=ss1.size()+len1[i-1];
		for(int j=len1[i-1];j<len1[i];j++){
			s1[j]=ss1[j-len1[i-1]];
			s2[j]=ss2[j-len1[i-1]];
		}
	}
	for(int i=1;i<=q;i++){
		for(int x=1;x<=n;x++){
			if(len1[i]-len1[i-1]<len2[x]-len2[x-1])break;
			for(int j=1;j<=len1[i]-len1[i-1]-len2[x]+len2[x-1]+1;j++){
				bool f=false;
				for(int y=len2[x-1];y<len2[x];y++){
					if(s1[len1[i-1]+y-len2[x-1]+j-1]==t1[y])f=true;
					else break;
				}
				if(f){
					for(int y=1;y<=len1[i]-len1[i-1]-len2[x]+len2[x-1]+1;y++){
						for(int k=len2[x-1];k<len2[x];k++){
							if(s2[len1[i-1]+k-len2[x-1]+y-1]==t2[k])f=false;
							
							else break;
						}
						if(!(f)){
							ans[i]++;
							break;
						}
					}
				}
			}
		}
	}
	for(int i=1;i<=q;i++)printf("%d\n",ans[i]);
	return 0;
}
