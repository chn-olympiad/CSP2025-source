#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
typedef long long ll;
char s[N];ll ans,cnt;
int a[1011];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	ll l=sizeof(s),cnt=0;
	if(l==1) ans=(int)s[0]-48;//4'get!
	else{
		for(int i=0;i<l;i++){
			if(s[i]>='0'&&s[i]<='9'){
				cnt++;
				a[cnt]=(int)s[i]-48;
			}
		}
		//for(int i=1;i<=cnt;i++)
				//cout<<a[i]<<" ";
		//cout<<endl;		
		sort(a+1,a+cnt);
		//for(int i=1;i<=cnt;i++)
				//cout<<a[i]<<" ";
	//}
		for(int i=1,m=1;i<=cnt;i++,m*=10){
			ans+=a[i]*m;
		}
	}
	cout<<ans<<endl;
	return 0;
}
