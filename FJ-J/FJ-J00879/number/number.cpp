#include<bits/stdc++.h>
const int maxx=1e6+50;
using namespace std;
int a[maxx],cnt=1;
bool b[maxx];
long long sum;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[cnt]=int(s[i])-48;
			b[cnt]=1;
			cnt++;
		}
	}
	for(int i=1;i<cnt;i++){
		int maxi=-1;
		int w;
		for(int j=1;j<cnt;j++){
			if(a[j]>maxi&&b[j]==1){
				maxi=a[j];
				w=j;
			}
		} 
		sum=sum*10+maxi;
		a[w]=0;
		b[w]=0;
	}
	printf("%lld",sum);
	return 0;
} 
