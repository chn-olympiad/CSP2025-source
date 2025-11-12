#include<bits/stdc++.h>
using namespace std;
namespace solve{
	#define int unsigned long long
	inline void read(int &x){
		x=0;char ch=getchar_unlocked();
		while(!isdigit(ch)){ch=getchar_unlocked();}
		while(isdigit(ch)){x=x*10+ch-48;ch=getchar_unlocked();}
	}
	int n,k,used=0;
	int a[500005],rlt=0;
	bitset<500005>v[20];
	bitset<500005>s[20];
	int last[20][2];
	inline bool get_bit(int x,int pos){
		return (x&(1<<pos))>>pos;}
	inline signed solve(){
		freopen("xor.in","r",stdin);
		freopen("xor.out","w",stdout);
		read(n);read(k);
		for(int i=1;i<=n;i++){
			read(a[i]);
			for(int j=0;j<20;j++){
				v[j][i]=get_bit(a[i],j);
				s[j][i]=s[j][i-1]^v[j][i];
			}
		}
		for(int i=0;i<20;i++)
			last[i][0]=last[i][1]=0;
		for(int i=1;i<=n;i++){
			int nearest[20],final=1145141919810;
			for(int j=0;j<20;j++){
				if(v[j][i]==0)last[j][v[j][i]]=i;
				if(get_bit(k,j)==v[j][i])nearest[j]=i;
				else nearest[j]=last[j][1];
				final=min(final,nearest[j]);
				last[j][v[j][i]]=i;
			}
			if(final<=used)continue;
			for(int u=used+1;u<=final;u++){
				bool vis=0;
				for(int j=0;j<20;j++)
					if((s[j][i]^s[j][u
						-1])!=get_bit(k,j)){
						vis=1;
						break;
					}
				if(!vis){
					rlt++;
					used=i;
					break;
				}
			}
		}
		cout<<rlt;
		return 0;
	}
	#undef int
}
int main(){return solve::solve();}