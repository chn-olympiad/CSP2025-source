//GZ-S00101 贵阳雅礼高级中学 周俞帆
#include<bits/stdc++.h>
using namespace std;
int t;
int n,z;
long long sum;
int f1,f2,f3;
struct node{
	int a1,a2,a3,s,ma,c1,c2,c3,xyz;
}a[100004];
bool cmp1(node s1,node s2){
	if(s1.s>s2.s)
		return s1.s<s2.s;
}
bool cmp2(node s1,node s2){
	if(s1.c1>s2.c1)
		return s1.c1<s2.c1;
}
bool cmp31(node s1,node s2){
	int sc11=s1.c1,sc12=s1.c2,sc21=s2.c1,sc22=s2.c2;
	if(sc11>sc12){
		if(sc12>sc21||sc12>sc22){
			return s1.c1>s2.c1;
		}else{
			return s1.c2<s2.c2;
		}
	}else{
		if(sc11>sc21||sc11>sc22){
			return s1.c2<s2.c2;
		}else{
			return s1.c1<s2.c1;
		}
	}
}
bool cmp32(node s1,node s2){
	int sc11=s1.c1,sc13=s1.c3,sc21=s2.c1,sc23=s2.c3;
	if(sc11>sc13){
		if(sc13>sc21||sc13>sc23){
			return s1.c1>s2.c1;
		}else{
			return s1.c3<s2.c3;
		}
	}else{
		if(sc11>sc21||sc11>sc23){
			return s1.c3<s2.c3;
		}else{
			return s1.c1<s2.c1;
		}
	}
}
bool cmp33(node s1,node s2){
	int sc12=s1.c2,sc13=s1.c3,sc22=s2.c2,sc23=s2.c3;
	if(sc12>sc13){
		if(sc13>sc22||sc13>sc22){
			return s1.c2>s2.c2;
		}else{
			return s1.c3<s2.c3;
		}
	}else{
		if(sc12>sc22||sc12>sc23){
			return s1.c3<s2.c3;
		}else{
			return s1.c2<s2.c2;
		}
	}
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		f1=1;f2=1;f3=1;
		cin>>n;
		sum=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			a[i].s=a[i].a1+a[i].a2+a[i].a3;
			a[i].ma=max(a[i].a1,max(a[i].a2,a[i].a3));
			if(a[i].a1!=0)f1=0;
			if(a[i].a2!=0)f2=0;
			if(a[i].a3!=0)f3=0;
		}
		if(f1+f2+f3==2){
			sort(a+1,a+1+n,cmp1);
			for(int i=n/2+1;i<=n;i++){
				sum+=a[i].s;
			}
			cout<<sum<<endl;
		}
		else if(f1+f2+f3==1){
			int l=0,r=0;
			if(f1==0&&f2==0){
				for(int i=1;i<=n;i++){
					a[i].c1=abs(a[i].a1-a[i].a2);
					if(a[i].c1==0)a[i].c1=200001;
					else{
						if(a[i].ma==a[i].a1){
							a[i].xyz=1;
							l++;
						}
						else{
							a[i].xyz=2;
							r++;
						}
					}
				}
			}
			else if(f1==0&&f3==0){
				for(int i=1;i<=n;i++){
					a[i].c1=abs(a[i].a1-a[i].a3);
					if(a[i].c1==0)a[i].c1=200001;
					else{
						if(a[i].ma==a[i].a1){
							a[i].xyz=1;
							l++;
						}
						else{
							a[i].xyz=2;
							r++;
						}
					}
				}
			}else{
				for(int i=1;i<=n;i++){
					a[i].c1=abs(a[i].a3-a[i].a2);
					if(a[i].c1==0)a[i].c1=200001;
					else{
						if(a[i].ma==a[i].a2){
							a[i].xyz=1;
							l++;
						}
						else{
							a[i].xyz=2;
							r++;
						}
					}
				}
			}
			for(int i=1;i<=n;i++){
				sum+=a[i].ma;
			}
			if(l<=n/2&&r<=n/2){
				cout<<sum<<endl;
			}else{
				sort(a+1,a+1+n,cmp2);
				int i=1;
				if(l>=n/2){
					z=l-n/2;
					while(z){
						if(a[i].xyz==1){
							sum-=a[i].c1;
							z--;
						}
						i++;
					}
				}else{
					z=r-n/2;
					while(z){
						if(a[i].xyz==2){
							sum-=a[i].c1;
							z--;
						}
						i++;
					}
				}
				cout<<sum<<endl;
			}
		} 
		else{
			int x=0,y=0,z=0;
			for(int i=1;i<=n;i++){
				a[i].c1=abs(a[i].a1-a[i].a2);
				a[i].c2=abs(a[i].a1-a[i].a3);
				a[i].c3=abs(a[i].a2-a[i].a3);
				if(a[i].c1==0&&a[i].c2==0){
					a[i].c1=200000;
					a[i].c2=200000;
					a[i].c3=200000;
				}else{
					if(a[i].ma==a[i].a1){
						a[i].xyz=1;
						x++;
					}
					if(a[i].ma==a[i].a2){
						a[i].xyz=2;
						y++;
					}
					if(a[i].ma==a[i].a3){
						a[i].xyz=3;
						z++;
					}
				}
			}
			for(int i=1;i<=n;i++){
				sum+=a[i].ma;
			}
			if(x<=n/2&&y<=n/2&&z<=n/2){
				cout<<sum<<endl;
			}else{
				int i,j=1;
				if(x>=n/2){
					cout<<1<<endl;
					sort(a+1,a+1+n,cmp31);
					i=x-n/2;
					while(i){
						if(a[j].xyz==1){
							if(a[j].c1>a[j].c2)sum-=a[j].c2;
							else sum-=a[j].c1;
							i--;
						}
						j++;
					}
				}else if(y>=n/2){
					cout<<2<<endl;
					sort(a+1,a+1+n,cmp32);
					i=y-n/2;
					while(i){
						if(a[j].xyz==2){
							if(a[j].c1>a[j].c3)sum-=a[j].c3;
							else sum-=a[j].c1;
							i--;
						}
						j++;
					}
				}else{
					cout<<3<<endl;
					sort(a+1,a+1+n,cmp33);
					i=z-n/2;
					while(i){
						if(a[j].xyz==3){
							if(a[j].c3>a[j].c2)sum-=a[j].c2;
							else sum-=a[j].c3;
							i--;
						}
						j++;
					}
				}
				cout<<sum<<endl;
			}
		}
	}
	return 0;
}
