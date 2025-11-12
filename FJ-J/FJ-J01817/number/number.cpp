#include<bits/stdc++.h>
namespace kqsscgtk{
	char c,s[1001001];int i,j,a[128];
	void M(){for(scanf("%s",s);c=s[i++];++a[c]);for(i=58;--i^47;)for(j=a[i];j--;putchar(i));}
}
int main(){return freopen("number.in","r",stdin),freopen("number.out","w",stdout),kqsscgtk::M(),0;}
