#include <bits/stdc++.h>
using namespace std;
vector<int> a,w;
int n,k,amt=0,maxm=0,MAXN=500000;

int weight(int l,int r){
	int x=a[l];
	for (int i=l+1;i<=r;i++)
		x^=a[i];
	return x;
}

void search(int x){
	int w=0,temp_i;
	for (int i=x;i<n;i++){
		w=a[i];
		temp_i=i;
		while (w!=k && i+1<=n) w^=a[++i];
		if (w==k) amt++;
		search(i+1);
		maxm=max(maxm,amt);
		amt--;
		i=temp_i;
	}
	return;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
	
    scanf("%d%d",&n,&k);
    a.resize(n+1,0);

    for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	search(1);
	printf("%d\n",maxm);
    return 0;
}


