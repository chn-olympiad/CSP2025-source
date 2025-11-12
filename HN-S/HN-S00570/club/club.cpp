#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[1000001];
struct c1{
	int name1;
	int b1;
}a1[1000001];
struct c2{
	int name2;
	int b2;
}a2[1000001];struct c3{
	int name3;
	int b3;
}a3[1000001];
bool cmp(c1 E,c1 F){
	return E.b1>F.b1;
}bool cmp1(c2 E,c2 F){
	return E.b2>F.b2;
}bool cmp2(c3 E,c3 F){
	return E.b3>F.b3;
}
int y1g2(int n,int k){
	for(int i=0;i<n;i++){
		if(a2[i].name2==k){
			return i;
		}
	}
}
int y1g3(int n,int k){
	for(int i=0;i<n;i++){
		if(a3[i].name3==k){
			return i;
		}
	}
}int y2g1(int n,int k){
	for(int i=0;i<n;i++){
		if(a1[i].name1==k){
			return i;
		}
	}
}int y2g3(int n,int k){
	for(int i=0;i<n;i++){
		if(a3[i].name3==k){
			return i;
		}
	}
}int y3g1(int n,int k){
	for(int i=0;i<n;i++){
		if(a1[i].name1==k){
			return i;
		}
	}
}int y3g2(int n,int k){
	for(int i=0;i<n;i++){
		if(a2[i].name2==k){
			return i;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int m;
	cin>>m;
	for(int i=1;i<=m;i++){
		int n,man=0;
		cin>>n;
		for(int i=0;i<n;i++){
			a1[i].name1=i;
			a2[i].name2=i;
			a3[i].name3=i;
			cin>>a1[i].b1>>a2[i].b2>>a3[i].b3;
		}
		sort(a1,a1+n,cmp);
		sort(a2,a2+n,cmp1);
		sort(a3,a3+n,cmp2);
	int n1=0;
	int m1=0,m2=0,m3=0;
		while(1){
			if(n1==n){
				break;
			}
			if(a1[m1].b1>=a2[m2].b2&&a1[m1].b1>=a3[m3].b3){
				if(m1>=n/2){
					if(a2[m2].b2>=a3[m3].b3&&m2<n/2){
						man+=a2[m2].b2;
						
						
						
						m2++;
						n1++;
						int kao=y2g1(n,a2[m2].name2);
						int cao=y2g3(n,a2[m2].name2);
						a1[kao].b1=0;
						a3[cao].b3=0; 
					
						
						continue;
					}else if(a2[m2].b2<a3[m3].b3&&m3<n/2){
						man+=a3[m3].b3;
						
						
						m3++;
						n1++;
						int kao=y3g1(n,a3[m3].name3);
						int cao=y3g2(n,a3[m3].name3);
						a1[kao].b1=0;
						a2[cao].b2=0;  //ok
						
						continue;
					}
				}else{
					man+=a1[m1].b1;
					
					m1++;
					n1++;
					int kao=y1g2(n,a1[m1].name1);
						int cao=y1g3(n,a1[m1].name1);
						a2[kao].b2=0;
						a3[cao].b3=0;  //ok
					
					
					continue;
				}
			}else if(a2[m2].b2>a1[m1].b1&&a2[m2].b2>=a3[m3].b3){
				if(m2>=n/2){
					if(a1[m1].b1>=a3[m3].b3&&m1<n/2){
						man+=a1[m1].b1;
						
						
						m1++;
						n1++;
						int kao=y1g2(n,a1[m1].name1);
						int cao=y1g3(n,a1[m1].name1);
						a2[kao].b2=0;
						a3[cao].b3=0;  //ok
						
					
						
						continue;
					}else if(a1[m1].b1<a3[m3].b3&&m3<n/2){
						man+=a3[m3].b3;
					
						m3++;
						n1++;
						int kao=y3g1(n,a3[m3].name3);
						int cao=y3g2(n,a3[m3].name3);
						a1[kao].b1=0;
						a2[cao].b2=0; //ok
						
					
						
						continue;
					}
				}else{
					man+=a2[m2].b2;
					
					m2++;
					n1++;
					int kao=y2g1(n,a2[m2].name2);
						int cao=y2g3(n,a2[m2].name2);
						a1[kao].b1=0;
						a3[cao].b3=0; //ok
					
					
					continue;
				}
			}else if(a3[m3].b3>a1[m1].b1&&a3[m3].b3>a2[m2].b2){
				if(m3>=n/2){
					if(a1[m1].b1>=a2[m2].b2&&m1<n/2){
						man+=a1[m1].b1;
						
						m1++;
						n1++;
						int kao=y1g2(n,a1[m1].name1);
						int cao=y1g3(n,a1[m1].name1);
						a2[kao].b2=0;
						a3[cao].b3=0; //ok
						
						
						
						continue;
					}else if(a1[m1].b1<a2[m2].b2&&m2<n/2){
						man+=a2[m2].b2;
						
					
						m2++;
						n1++;
						int kao=y2g3(n,a2[m2].name2);
						int cao=y2g1(n,a2[m2].name2);
						a3[kao].b3=0;
						a1[cao].b1=0; //ok
						
						continue;
					}
				}else{
					man+=a3[m3].b3;
					
					m3++;
					n1++;
					int kao=y3g1(n,a3[m3].name3);
						int cao=y3g2(n,a3[m3].name3);
						a1[kao].b1=0;
						a2[cao].b2=0; //ok
					
					continue;
				}
				continue;
			}
		}
		cout<<man<<endl;
	}
	return 0;
}
