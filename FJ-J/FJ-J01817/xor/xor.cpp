#include<bits/stdc++.h>
namespace kqsscgtk{
	int n,k,i,s,r,a,m,p[1111111];
	void M(){for(*p=1,scanf("%d%d",&n,&k);i++^n;m^=a,p[m^k]>r?++s,r=i:0,p[m]=i+1)scanf("%d",&a);printf("%d",s);}
}
int main(){return freopen("xor.in","r",stdin),freopen("xor.out","w",stdout),kqsscgtk::M(),0;}
