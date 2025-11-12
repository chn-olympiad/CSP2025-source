#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1[200005],s2[200005];
string t1,t2;
int l1[200005];
int L1;
int sum;
bool pan(int x){
	for(int o=x;o<L1;o++){
		if(t1[o]!=t2[o]){
			return false;
		}
	}
	return true;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		l1[i]=s1[i].size();
	}
	while(q--){
		cin>>t1>>t2;sum=0;
		L1=t1.size();
		for(int i=1;i<=n;i++){
			if(s1[i]==t1 and s2[i]==t2){
				sum++;
			}
			else if(l1[i]<L1){
				for(int j=0;j<L1-l1[i]+1;j++){
					bool ji=true;
					for(int p=0;p<l1[i];p++){
						if(s1[i][p]!=t1[j] or s2[i][p]!=t2[j]){
							ji=false;break;
						}
					}
					if(ji){
						if(pan(j+1)){sum++;}
						break;
					}
				}
			}
		}
		printf("%d\n",sum);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
