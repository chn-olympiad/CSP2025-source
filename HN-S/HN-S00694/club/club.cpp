#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	int t;
	cin>>t;
	for(int z=0;z<t;z++){
		int n,a[10005],b[10005],c[10005],mna=99999,mia=99999,mxxa=0;
		int c1=0,c2=0,c3=0,sum=0;
		int mxna=99999,mxnb=99999,mxnc=99999;
		int mxxb=0,mxxc=0;
		int mnb=0,mnc=0;
		int mib=0,mic=0;
		int ax,bx,cx;
		int inc1[10005],inc2[10005],inc3[10005],na=0,nb=0,nc=0;
		int key=0,jin=0;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		for(int i=0;i<n;i++){
			key=0;
			if(a[i]>b[i] && a[i]>c[i]){
				c1++;
				//cout<<"mx"<<a[mxxa]-b[mxxa]<<endl;
				//cout<<"i"<<a[i]-b[i]<<endl;
				if(c1>n/2){
					//cout<<"uyyyyy";
						if(ax==1 && c2+1<=n/2){
						
						if(a[mxxa]-b[mxxa]<a[i]-b[i]){
							//cout<<"sum"<<sum<<endl;
						 	sum-=a[mxxa]-b[mxxa];
						 	//cout<<"sum"<<sum<<endl;
						 	sum+=a[i]-b[i];
						 	//cout<<"sum"<<sum<<endl;
							c2++;
							c1--;
							key=0;
							break;
						}else{
							sum-=a[i]-b[i];
							sum+=a[mxxa]-b[mxxa];
							c3++;
							c1--;
							//na++;
						}
					if(mxna>=a[i]){
						if(a[mxxa]-c[mxxa]<a[i]-c[i]){
							sum-=a[mxxa]-c[mxxa];
							c3++;
							c1--;
						}else{
							sum-=a[i]-c[i];
							c3++;
							c1--;
							na++;
						}
					}
					}else{
						key=1;
						jin=1;
					}
					if(key==0){
					
					inc1[na]==999999999;
					mxna=99999999;
					for(int j=0;j<ax;j++){
						if(inc1[j]<=mxna){
							mxna=inc1[j];
							na=j;
							if(a[j]-b[j]>=a[j]-c[j] && mia>a[j]-c[j]){
								mia=a[j]-c[j];
								ax=2;
							}else{
								mia=a[j]-b[j];
								ax=1;
							}
						}
					}
					}
					
				}
				if(key==0){
				
				sum+=a[i];
				if(a[i]<mxna){
					mxna=a[i];
					mxxa=i;
					inc1[ax]=a[i];
					na=i;
					ax++;
				}
				if(a[i]-b[i]>=a[i]-c[i] && mia>a[i]-c[i]){
					mia=a[i]-c[i];
					ax=2;
				}else{
					mia=a[i]-b[i];
					ax=1;
				}
				}
			}else if(a[i]<=b[i])key=1;
			if(b[i]>c[i] && key==1){
				//if(key==1)cout<<"succeed";
				c2++;
				if(c2>n/2){
					//cout<<"c2>n/2"<<endl;
					if(bx==1 && c1+1<n/2){
							if(b[mxxb]-a[mxxb]<b[i]-a[i]){
							
							//sum-=b[mxxb]-a[mxxb];
							sum+=b[i]+a[i];
							c1++;
							c2--;
							key=0;
							break;
							
						}else{
							sum-=b[i]-a[i];
							sum+=b[mxxb]-a[mxxb];
							c3++;
							c2--;
							nb++;
						}
						}else{
							if(b[mxxb]-c[mxxb]<b[i]-c[i]){
								sum-=b[mxxb]-c[mxxb];
								c3++;
								c2--;
							}else{
								sum-=b[i]-c[i];
								c3++;
								c2--;
								nb++;
							}
						}
					if(mxnb>=b[i]){
						key = 2;
						jin = 2;
					}
				}
				if(key!=2){
				
					inc2[nb]==999999999;
					mxnb=99999999;
					for(int j=0;j<bx;j++){
						if(inc2[j]<=mxnb){
							mxnb=inc2[j];
							nb=j;
							if(b[j]-a[j]>=b[j]-c[j] && mib>b[j]-c[j]){
								mib=b[j]-c[j];
								bx=2;
							}else{
								mib=b[j]-a[j];
								bx=1;
						}
					}
				}
				}
				if(key!=2){
				
				sum+=b[i];
				
				if(b[i]<mxnb){
					mxnb=b[i];
					mxxb=i;
					inc2[bx]=b[i];
					nb=i;
					bx++;
				}
				if(jin==1){
					if(mib>b[i]-c[i]){
						bx=2;
						mib=b[i]-c[i];
					}
				}else{
				if(b[i]-a[i]>=b[i]-c[i] && mib>b[i]-c[i]){
					mib=b[i]-c[i];
					bx=2;
				}else{
					mib=b[i]-a[i];
					bx=1;
				}
				}
				}
			}else if(b[i]<=c[i] && a[i]<=c[i]){
				key=2;
			}
			if(key==2){
				c3++;
			
				if(c2>=n/2){
					if(mxnc<c[i]){
						if(cx==1 && c1+1<n/2){
							if(c[mxxc]-a[mxxc]<c[i]-a[i]){
							
							sum-=c[mxxc]-a[mxxc];
							c1++;
							c3--;
							
						}else{
							sum-=c[i]-a[i];
							c1++;
							c3--;
							nc++;
						}
						}else{
							if(c[mxxc]-b[mxxc]<c[i]-b[i]){
							
							sum-=c[mxxc]-b[mxxc];
							c2++;
							c3--;
							
						}else{
							sum-=c[i]-b[i];
							c2++;
							c3--;
							nc++;
						}
					}
					}
					inc3[nc]==999999999;
					mxnc=99999999;
					for(int j=0;j<cx;j++){
						if(inc3[j]<=mxnc){
							mxnc=inc3[j];
							nc=j;
							if(c[j]-a[j]>=c[j]-b[j] && mic>c[j]-b[j]){
								mic=c[j]-b[j];
								cx=2;
							}else{
								mic=c[j]-a[j];
								cx=1;
							}
						}
					}
					
				}
				sum+=c[i];
				if(c[i]<mxnc){
					mxnc=c[i];
					mxxc=i;
					inc3[cx]=c[i];
					nc=i;
					cx++;
				}
				if(jin!=2){
					if(c[i]-a[i]>=c[i]-b[i] && mic>c[i]-b[i]){
						mic=c[i]-b[i];
						cx=2;
					}else{
						mic=c[i]-a[i];
						cx=1;
					}
				}
				 
				
				
			}
		}
		cout<<sum<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
