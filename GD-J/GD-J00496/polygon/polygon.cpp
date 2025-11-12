#include <iostream>
#include <algorithm>
using namespace std;
inline int read(){
	int f=1,s=0;
	char t=getchar();
	while(t<'0'||t>'9'){
		if(t=='-'){
			f=-1;
		}
		t=getchar();
	}
	while(t>='0'&&t<='9'){
		s=s*10+t-'0';
		t=getchar();
	}
	return f*s;
}
const int N=5e5+10;
const int mod=998244353;
int n,a[N],ans,s[N],lst[N];
bool cmp(int a,int b){
	return a<b;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(int x=7;x<=(1<<n)-1;x++){
		fill(lst+1,lst+n+1,0);
		int temp=x;
		int maxi=0,_num=0;
		while(temp){
			maxi++;
			_num+=temp&1;
			if(temp&1){
				lst[_num]=maxi;
			}
			temp>>=1;
		}
		/*cout<<x<<":"<<endl;
		cout<<"maxi:"<<maxi<<" _num:"<<_num<<endl;
		for(int i=1;i<=_num;i++){
			cout<<lst[i]<<" ";
		}
		cout<<endl;*/
		if(a[maxi]>s[maxi-1]){
			x=(1<<maxi)-1;
			continue;
		}
		if(_num<3){
			continue;
		}
		int sum=0;
		for(int i=1;i<=_num-1;i++){
			sum+=a[lst[i]];
		}
		if(sum>a[maxi]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
