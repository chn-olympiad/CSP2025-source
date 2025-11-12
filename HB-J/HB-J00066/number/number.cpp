#include<bits/stdc++.h>
using namespace std;
int s[1000005];
int ss;
int i=1,q=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>ss;
	while(ss>0){
		s[i]=ss%10;
		ss/=10;
		i++;
	}
	for(int k=1;k<i;k++){
		int maxn=-1;
		if(maxn==-1){
			for(int j=1;j<=i;j++){
				if(maxn<s[j]){
					maxn=max(maxn,s[j]);
					q=j;
				}
			}
		}
		cout<<maxn;
		s[q]=-1;
	}

	return 0;
}
