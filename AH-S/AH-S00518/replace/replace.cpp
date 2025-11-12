#include<iostream>
#include<algorithm>
#include<string.h>
#include<cmath>

#define LL long long

using namespace std;

const int N=2*1e5+10;

int n,q;
string s1[N],s2[N];
string t1,t2;

int main(){

    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);

    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)
		cin>>s1[i]>>s2[i];
	for(int i=1;i<=q;i++){
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			printf("0\n");
			continue;
		}
		int len=t1.size();
		int l=-1,r=-1;
		for(int j=0;j<len;j++)
			if(t1[j]!=t2[j]){
				r=j;
				if(l==-1)l=j;
			}
		string st1="",st2="";
		for(int j=l;j<=r;j++)
			st1+=t1[j],st2+=t2[j];
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(s1[j].find(st1)==NULL||s2[j].find(st2)==NULL)
				continue;
			if(t1.find(s1[j])==NULL||t2.find(s2[j])==NULL)
				continue;
			cnt++;
		}
		printf("%d\n",cnt);
	}
    return 0;

    fclose(stdin);
    fclose(stdout);

}
