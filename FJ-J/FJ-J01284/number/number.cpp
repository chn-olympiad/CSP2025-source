#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1000005];
long long cnt=0;
int cmp(long x,long y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	//scanf("%s",&s);
	int m=s.size();
	for(int i=0;i<m;i++){
		if(s[i]>='0' and s[i]<='9'){
			cnt+=1;
			a[cnt]=s[i]-'0';
			
		}
	}
	sort(a+1,a+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		cout<<a[i];
		//printf("%d",a[i]);
	}
	cout<<"\n";
	//printf("\n");
	return 0;
}
