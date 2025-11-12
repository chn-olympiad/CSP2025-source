#include <bits/stdc++.h>
using namespace std;

int a[100010][3],b[100010],c[100010],d[100010],b2[100010],c2[100010],d2[100010];
int q,p,b1=0,c1=0,d1=0;
void ma(int i){
	q=a[i][0],p=0;
	if(a[i][1]>q){
		q=a[i][1];
		p=1;
		return;
	}else if(a[i][2]>q){
		q=a[i][2];
		p=2;
		return;
	}
	return;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t; cin>>t;
	for(int k=0;k<t;k++){
		int n;cin>>n;
		if(n==2){
			int l1,l2,l3,l4,l5,l6;
			cin>>l1>>l2>>l3>>l4>>l5>>l6;
			int f[10]{};
			f[1]=l1+l5;
			f[2]=l1+l6;
			f[3]=l2+l4;
			f[4]=l2+l6;
			f[5]=l3+l4;
			f[0]=l3+l5;
			sort(f,f+6);
			cout<<f[5]<<endl;
		}else{
			b1=0,c1=0,d1=0;
			for(int i=0;i<n;i++){
				cin>>a[i][0]>>a[i][1]>>a[i][2];\
				ma(i);
				if(p==0){
					b[b1++]=q;
					b2[b1]=0;
				}else if(p==1){
					c[c1++]=q;
					c2[c1]=1;
				}else if(p==2){
					d[d1++]=q;
					d2[d1]=2;
				}
			}
//			cout<<b1<<' '<<c1<<' '<<d1<<endl;
			if(b1<=n/2&&c1<=n/2&&d1<=n/2){
				int s=0;
				for(int i=0;i<b1;i++) s+=b[i];
				for(int i=0;i<c1;i++) s+=c[i];
				for(int i=0;i<d1;i++) s+=d[i];
				cout<<s<<endl;
			}else{
				int s=0;
				if(b1>n/2){
					for(int i=1;i<b1;i++){
						for(int j=i+1;j<b1;j++){
							if(b[j]>b[j-1]){
								int place=b[j-1];
								b[j-1]=b[j];
								b[j]=place;
								place=b2[j-1];
								b2[j-1]=b[j];
								b2[j]=place;
							}
						}
					}
					for(int i=0;i<n/2;i++){
						s+=b[i];
					}
					for(int i=n/2;i<b1;i++){
						s+=max(a[b2[i]][0],a[b2[i]][2]);
					}
				}
				if(c1>n/2){
					for(int i=1;i<c1;i++){
						for(int j=i+1;j<c1;j++){
							if(c[j]>c[j-1]){
								int place=c[j-1];
								c[j-1]=c[j];
								c[j]=place;
								place=c2[j-1];
								c2[j-1]=c[j];
								c2[j]=place;
							}
						}
					}
					for(int i=0;i<n/2;i++){
						s+=c[i];
					}
					for(int i=n/2;i<c1;i++){
						s+=max(a[c2[i]][0],a[c2[i]][2]);
					}
				}
				if(d1>n/2){
					for(int i=1;i<d1;i++){
						for(int j=i+1;j<d1;j++){
							if(d[j]>d[j-1]){
								int place=d[j-1];
								d[j-1]=d[j];
								d[j]=place;
								place=d2[j-1];
								d2[j-1]=d[j];
								d2[j]=place;
							}
						}
					}
					for(int i=0;i<n/2;i++){
						s+=d[i];
					}
					for(int i=n/2;i<d1;i++){
						s+=max(a[d2[i]][0],a[d2[i]][2]);
					}
				}
				cout<<s<<endl;
			}
		}
		
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
