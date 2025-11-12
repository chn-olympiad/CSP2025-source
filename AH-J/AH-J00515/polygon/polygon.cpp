#include <bits/stdc++.h>
using namespace std;
int n,amt=0;
vector<int> l,total_length;

int cal(int s,int t){
	int z=0,t1=t;
	for (int i=0;i<t1;i++){
		z+=z%998244353+(t*(s+1))%998244353;
		t--;
		s++;
	}
	return z%998244353;
}

int main(){
	freopen("polygon3.in","r",stdin);
	freopen("polygon.out","w",stdout);
    
    scanf("%d",&n);
    if (n<3) {
		printf("0\n");
		return 0;
	}
	l.resize(n+1,0);
	total_length.resize(n+1,0);
	for (int i=1;i<=n;i++){
		scanf("%d",&l[i]);
	}
	sort(l.begin(),l.end());
	for (int i=1;i<=n;i++){
		total_length[i]=total_length[i-1]+l[i];
	}
	int tail=n, tot=total_length[n], tot_temp, maxl;
    
    for (;tail>=3;tail--){
		maxl=l[tail];
		tot_temp=tot;
		for (int i=1;i<tail-1;i++){
			if (tot-maxl<=maxl) break;
			int j=i;
			while (total_length[j]<=maxl && j<tail) j++;
			int s=j-i+1,t=tail-j-1;
			
			amt+=cal(s,t)%998244353;
		}
		tot=tot_temp-maxl;
	}
		

	printf("%d\n",amt);
    return 0;
}




