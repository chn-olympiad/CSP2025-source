#include <bits/stdc++.h>
using namespace std;
int a[500055],ejz1[29],ejz2[29],yihuo[29];
int ejz_one(int cs){
	int xb=0;
	for (int i=0;i<=29;i++)ejz1[i]=0;
	while (cs!=0){
		ejz1[++xb]=cs%2;
		cs/=2;
	}
	return xb;
}
int ejz_two(int cs){
	int xb=0;
	for (int i=0;i<=29;i++)ejz2[i]=0;
	while (cs!=0){
		ejz2[++xb]=cs%2;
		cs/=2;
	}
	return xb;
}
int yi_huo(int xb1,int xb2){
	int i;
	for (i=0;i<max(xb1,xb2);i++){
		if (ejz1[i+1]==ejz2[i+1])yihuo[i]=0;
		else yihuo[i]=1;
	}
	return i;
}
struct Node{
	int s;
	int e;
}l[4000005];
int sjz_(int xb){
	int fhz=0;
	for (int i=0;i<=xb;i++){
		fhz+=yihuo[i]*pow(2,i);;
	}return fhz;
}
bool cmp(Node s1,Node s2){
	return s1.e<s2.e;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);	
	int n,k;
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	if (n==1 && k==0){
		if (a[1]==0) printf("1");
		else printf("0");
	}else if (n==2 && k==0){
		if (a[1]==0 && a[2]==0) printf("2");
		else if (a[1]==a[2]) printf("1");
		else printf("0");
	}else{
		int num=0;
		for (int i=1;i<=n;i++){
			for (int j=i+1;j<=n;j++){
				int cz=a[i];
				for (int k=i+1;k<=j;k++){
					int len1=ejz_one(cz);
					int len2=ejz_two(a[k]);
					int len3=yi_huo(len1,len2);
					cz=sjz_(len3);
				}
				if (cz==k){
					l[++num].s=i;
					l[num].e=j;
				}
			}
			if (a[i]==k){
				l[++num].s=i;
				l[num].e=i;
			}
		}
		sort(l+1,l+num+1,cmp);
		int ans=1;
		int lastend=l[1].e;
		for (int i=2;i<=num;i++){
			if (l[i].s>lastend){
				ans++;
				lastend=l[i].e;
			}
		}
		printf("%d",ans);	
	}
	return 0;
}
