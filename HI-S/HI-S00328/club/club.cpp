#include<bits/stdc++.h>
using namespace std;
int t,c[11],po=0;
struct qwe{
	int q,w,e,r;
}a[100001];
struct qwe1{
	int s,num;
}b[10];
bool dfs3(int n){
	int sum=0;
	for(int i=1;i<=n;i++){
		if(a[i].w!=0 || a[i].e!=0){
			sum=1;
		}
	}
	if(sum==1) return false;
	else return true;
}
int dfs1(int n){
	int tyu=0;
	for(int i=1;i<=n;i++){
		tyu+=a[i].q;
	}
	return tyu;
}
bool dfs2(int n){
	int sum=0;
	for(int i=1;i<=n;i++){
		if(a[i].e!=0){
			sum=1;
		}
	}
	if(sum==1) return false;
	else return true;
}
bool cmp(qwe x,qwe y){
	return x.q>y.q;
}
bool cmp1(qwe x,qwe y){
	return x.r>y.r;
}
bool cmp2(qwe1 x,qwe1 y){
	return x.s>y.s;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		int ans1=0,ans2=0,ans3=0;
		int n,max1=0,max2=0,yi=0,er=0,sa=0;
		cin >> n;
		int n1=n/2;
		for(int i=1;i<=n;i++){
			cin >> a[i].q>> a[i].w >> a[i].e;
			a[i].r=a[i].q+a[i].w+a[i].e;
		}		
		sort(a+1,a+n+1,cmp1);
		if(dfs3(n)==true){
			sort(a+1,a+n+1,cmp);
			ans1+=dfs1(n1);
		}		
		else if(dfs2(n)==true){
			for(int i=1;i<=n;i+=2){
				if(yi+1<=n1 && er+1<=n1 && a[i].q+a[i+1].w>a[i].w+a[i+1].q){
					yi++;
					er++;
					ans1+=a[i].q;
					ans2+=a[i+1].w;
				}
				else if(yi+1<=n1 && er+1<=n1 && a[i].q+a[i+1].w<a[i].w+a[i+1].q){				
					yi++;
					er++;
					ans1+=a[i+1].q;
					ans2+=a[i].w;
				}
				else if(a[i].q+a[i+1].q>=a[i].w+a[i+1].w && yi+2<=n1){
					yi+=2;
					ans1+=a[i].q+a[i+1].q;
				}
				else if(a[i].q+a[i+1].q<=a[i].w+a[i+1].w && er+2<=n1){
					er+=2;
					ans2+=a[i].w+a[i+1].w;
				}
			}
		}
		else{
			for(int i=1;i<=n;i+=2){
				b[1].s=a[i].q+a[i+1].q,b[1].num=1;
				b[2].s=a[i].q+a[i+1].w,b[2].num=2;
				b[3].s=a[i].q+a[i+1].e,b[3].num=3;
				b[4].s=a[i].w+a[i+1].q,b[4].num=4;
				b[5].s=a[i].w+a[i+1].w,b[5].num=5;
				b[6].s=a[i].w+a[i+1].e,b[6].num=6;
				b[7].s=a[i].e+a[i+1].q,b[7].num=7;
				b[8].s=a[i].e+a[i+1].w,b[8].num=8;
				b[9].s=a[i].e+a[i+1].e,b[9].num=9;
				sort(b+1,b+10,cmp2);
				int j=1;
				while(1){
					if(b[j].num==1){
						if(yi+2<=n1){
							yi++,yi++;
							ans1+=a[i].q,ans1+=a[i+1].q;
							break;
						}
						else j++;
					}
					else if(b[j].num==2){
						if(yi+1<=n1 && er+1<=n1){
							yi++,er++;
							ans1+=a[i].q,ans2+=a[i+1].w;
							break;
						}
						else j++;
					}
					else if(b[j].num==3){
						if(yi+1<=n1 && sa+1<=n1){
							yi++,sa++;
							ans1+=a[i].q,ans3+=a[i+1].e;
							break;
						}
						else j++;
					}
					else if(b[j].num==4){
						if(er+1<=n1 && yi+1<=n1){
							yi++,er++;
							ans2+=a[i].w,ans1+=a[i+1].q;
							break;
						}
						else j++;
					}
					else if(b[j].num==5){
						if(er+2<=n1){
							er++,er++;
							ans2+=a[i].w,ans2+=a[i+1].w;
							break;
						}
						else j++;
					}
					else if(b[j].num==6){
						if(er+1<=n1 && sa+1<=n1){
							sa++,er++;
							ans2+=a[i].w,ans3+=a[i+1].e;
							break;
						}
						else j++;
					}
					else if(b[j].num==7){
						if(sa+1<=n1 && yi+1<=n1){
							sa++,yi++;
							ans3+=a[i].e,ans1+=a[i+1].q;
							break;
						}
						else j++;
					}
					else if(b[j].num==8){
						if(sa+1<=n1 && er+1<=n1){
							sa++,er++;
							ans3+=a[i].e,ans2+=a[i+1].w;
							break;
						}
						else j++;
					}
					else if(b[j].num==9){
						if(sa+2<=n1){
							sa+=2;
							ans3+=a[i].e+a[i+1].e;
							break;
						}
						else j++;
					}
				}		
			}			
		}			
		po++;
		c[po]=ans1+ans2+ans3; 
	}
	for(int i=1;i<=po;i++){
		cout << c[i] << endl;
	}
	return 0;
}

