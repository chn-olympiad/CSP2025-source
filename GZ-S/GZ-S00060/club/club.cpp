//GZ-S00060 都匀市第三中学 刘盾 
#include<bits/stdc++.h> 
using namespace std;
int t,n,bt,y,e,s;
int a[100005],b[100005],c[100005],d[3];
int main(){
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		int ct=0;
		y=0,e=0,s=0;
		scanf("%d",&n);
		bt=n/2;
		for(int i=0;i<n;i++)cin>>a[i]>>b[i]>>c[i];
		sort(a,a+n);
		sort(b,b+n);
		sort(c,c+n);
//		printf("\n");
//		for(int i=n-1;i>=0;i--)printf("%d %d %d\n",a[i],b[i],c[i]);
		for(int i=n-1;i>=0;i--){
			if(y+e+s==n)break;
			if(y<=bt){
				y++;
				ct+=a[i];
//				printf("a[i]=%d\n",a[i]);
			}
			if(y+e+s==n)break;
			if(e<=bt){
				ct+=b[i];
				e++;
//				printf("b[i]=%d\n",b[i]);
			}
			if(y+e+s==n)break;
			if(s<=bt){
				ct+=c[i];
				s++;
//				printf("c[i]=%d\n",c[i]);
			}
			if(y+e+s==n)break;
			if(n-(y+e+s)==1){
				if(a[i]>b[i]&&a[i]>c[i]&&y<bt){
					ct+=a[i];
				}else if(b[i]>a[i]&&b[i]>c[i]&&e<bt){
					ct+=b[i];
				}else if(c[i]>a[i]&&c[i]>b[i]&&s<bt){
					ct+=c[i];
				}else if(b[i]==a[i]&&b[i]==c[i]&&a[i]==c[i]){
					if(y<ct){
						ct+=a[i];
					}else if(e<ct){
						ct+=b[i];
					}else if(s<ct){
						ct+=c[i];
					}
				}
			}else if(n-(y+e+s)==2){
				if(y<bt&&e<bt)ct+=a[i],ct+=b[i];
				if(y+e+s==n)break;
				if(y<bt&&s<bt)ct+=a[i],ct+=c[i];
				if(y+e+s==n)break;
				if(e<bt&&s<bt)ct+=b[i],ct+=c[i];
			}
		}
		printf("%d\n",ct);
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
//1
//4
//0 1 0
//0 1 0
//0 2 0
//0 2 0


