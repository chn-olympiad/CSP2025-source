#include<bits/stdc++.h>
using namespace std;
long long a[100006],l,cnt=0,ma;
string p;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	memset(a,0,sizeof(a));
	cin>>p;
	l=p.size();
	for(int i=0;i<=l;i++){
		if(p[i]<='9'&&p[i]>='0'){
			cnt++;
			a[cnt]=int(p[i])-'0';
		}
	}
	for(int i=1;i<=cnt;i++){
		ma=i;
		for(int j=i+1;j<=cnt;j++){
			if(a[ma]<=a[j]){
				ma=j;
			}
		}
		swap(a[i],a[ma]);
		cout<<a[i];
	}
	return 0;
}
