#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
inline int in(){
	int k=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&& c<='9'){
		k=k*10+c-'0';
		c=getchar();
	}
	return f*k;
}//n<=1e5
int ahash[20000][20000];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n=in(),q=in();
	for(int i=1;i<=n;i++){
		string a,b;cin >> a >> b;
		int la=a.size(),lb=b.size(),na=0,nb=0;
		for(int i=0;i<la;i++) na+=a[i]-'0';
		for(int i=0;i<lb;i++) nb+=b[i]-'0';
		ahash[na][nb]=ahash[nb][na]=1;
	}
	string a,b;
	while(q--){cin >> a >> b;
		int la=a.size(),lb=b.size(),ai[50005],bi[50005];
		if(la!=lb){
			cout << 0 << "\n";
			continue;
		}
		ai[0]=a[0]-'0',bi[0]=b[0]-'0';
		for(int i=1;i<la;i++){
			ai[i]=ai[i-1]+a[i]-'0';
			bi[i]=bi[i-1]+b[i]-'0';
		}
		int cnt=0;
		if(ahash[ai[0]][bi[0]]&&ai[lb-1]-ai[0]==bi[lb-1]-bi[0]) cnt++;
		for(int l=1;l<la;l++){
			for(int r=l;r<la;r++){
				if(ahash[ai[r]-ai[l-1]][bi[r]-bi[l-1]] && ai[l]==bi[l] && ai[lb-1]-ai[r]==bi[lb-1]-bi[r]){
				cnt++;
				}
			}
		}
		cout << cnt <<"\n";
	}
	return 0;
} 
