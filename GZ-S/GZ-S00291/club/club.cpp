//GZ-S00291 遵义市第四中学 殷震博 
#include<bits/stdc++.h>
using namespace std;
int T,n;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    scanf("%d",&T);
    while(T--){
    	scanf("%d",&n);
    	long long f=0;
    	int a_ch[n+5],b_ch[n+5],c_ch[n+5],aa=0,bb=0,cc=0,a_i=1,b_i=1,c_i=1,z=n;
    	memset(a_ch,0,sizeof(a_ch));
    	memset(b_ch,0,sizeof(b_ch));
    	memset(c_ch,0,sizeof(c_ch));
    	while(z--){
    		int a,b,c;
    		scanf("%d%d%d",&a,&b,&c);
    		f+=max(a,max(b,c));
    		if(max(a,max(b,c))==a)aa++,a_ch[a_i++]=a+min(a,min(b,c))-b-c;
    		else if(max(a,max(b,c))==b)bb++,b_ch[b_i++]=b+min(a,min(b,c))-a-c;
    		else cc++,c_ch[c_i++]=c+min(a,min(b,c))-a-b;
		}
		if(aa>n/2){
			sort(a_ch+1,a_ch+aa+1);
			for(int i=1;aa>n/2;i++,aa--)
			    f-=a_ch[i];
		}
		else if(bb>n/2){
			sort(b_ch+1,b_ch+bb+1);
			for(int i=1;bb>n/2;i++,bb--)
			    f-=b_ch[i];
		}
		else if(cc>n/2){
			sort(c_ch+1,c_ch+cc+1);
			for(int i=1;cc>n/2;i++,cc--)
			    f-=c_ch[i];
		}
		printf("%d\n",f);
	}
	return 0;
}
