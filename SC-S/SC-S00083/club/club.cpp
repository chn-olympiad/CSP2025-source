#include<iostream> 
using namespace std;
void f(int a[],int mina[],int i,int s[]){
		s[i]=s[i-1]+a[i];
		if(a[i]<a[mina[i-1]]) mina[i]=i;
		else mina[i]=mina[i-1]; 
}
void f1(int a[],int mina[],int i1,int i2,int s[]){
	s[i1]+=a[i2];
	if(a[i1]<a[mina[i2]]) mina[i1]=i1;
	else mina[i1]=mina[i2];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t>0){
		int n;
		cin>>n;
		int a[n+1],b[n+1],c[n+1],s[n+1]={0},na=0,nb=0,nc=0,mina[n+1]={1},minb[n+1]={1},minc[n+1]={1};
		s[0]=0,a[0]=0,b[0]=0,c[0]=0;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		for(int i=1;i<=n;i++){
			if(na!=n/2&&nb!=n/2&&nc!=n/2){
				if(a[i]>=b[i]&&a[i]>=c[i]){
					f(a,mina,i,s);
					na++;
					continue;
				}
				 else if(b[i]>=a[i]&&b[i]>=c[i]){
				 	f(b,minb,i,s);
				 	 nb++;
				 	continue;
				 }
				 else{
				 	f(c,minc,i,s);
				 	nc++;
				 	continue;
				 }
			}
			else{
				if(a[i]>=b[i]&&a[i]>=c[i]){
				if(s[i-1]-a[mina[i-1]]+a[i]+b[mina[i-1]]>s[i-1]||s[i-1]-a[mina[i-1]]+a[i]+c[mina[i-1]]>s[i-1]){
					s[i]=s[i-1]-a[mina[i-1]]+a[i];
					mina[i]=mina[i-2];
					if(b[mina[i-1]]>c[mina[i-1]]){
						f1(b,minb,i,mina[i-1],s);
						continue;
					}
					else{
						f1(c,minc,i,mina[i-1],s);
						continue;
					}
				}
				else{
					if(s[i-1]+b[i]>s[i-1]+c[i]){
						f(b,minb,i,s);
						nb++;
				 		continue;
					}
					else{
					f(c,minc,i,s);
					nc++;
				 	continue;
					}
				}
			}
		
				else if(b[i]>=a[i]&&b[i]>=c[i]){
				if(s[i-1]-b[minb[i-1]]+b[i]+a[minb[i-1]]>s[i-1]||s[i-1]-b[minb[i-1]]+b[i]+c[minb[i-1]]>s[i-1]){
					s[i]=s[i-1]-b[minb[i-1]]+b[i];
					minb[i]=minb[i-2];
					if(a[minb[i-1]]>c[minb[i-1]]){
						f1(a,mina,i,minb[i-1],s);
						continue;
					}
					else{
						f1(c,minc,i,minb[i-1],s);
						continue;
					}
				}
				else{
					if(s[i-1]+a[i]>s[i-1]+c[i]){
						f(a,mina,i,s);
						na++;
				 		continue;
					}
					else{
					f(c,minc,i,s);
					nc++;
				 	continue;
					}
				}
			}
			else {
				if(s[i-1]-c[minc[i-1]]+c[i]+a[minc[i-1]]>s[i-1]||s[i-1]-c[minc[i-1]]+c[i]+b[minc[i-1]]>s[i-1]){
					s[i]=s[i-1]-c[minc[i-1]]+c[i];
					minc[i]=minc[i-2];
					if(b[minc[i-1]]>a[minc[i-1]]){
						f1(b,minb,i,minc[i-1],s);
						continue;
					}
					else{
						f1(a,mina,i,minc[i-1],s);
						continue;
					}
				}
				else{
					if(s[i-1]+b[i]>s[i-1]+a[i]){
						f(b,minb,i,s);
						nb++;
				 		continue;
					}
					else{
						f(a,mina,i,s);
						na++;
				 	continue;
					}
				}
			}
		}
	}
		cout<<s[n]<<endl;
		t--;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}