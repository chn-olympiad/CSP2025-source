#include<iostream>
#include<algorithm>
using namespace std;
int t,n,a1,a2,a3,ss1,ss2,ss3;
long long a11,a22,a33,mm1,mm2,mm3,mm4;
bool f1,f2,f3;
struct node{
	int n1;
	int m1,m2,m3,ok1,ok2;
}o[100001];
bool compare2(node x1,node x2){
	if(x1.m2<x2.m2) return true;
	else return false;
}
bool cc1(node x1,node x2){
	if(ss1){
		mm2=x1.m1,mm4=x2.m1;
		if(x1.m2>x1.m3){
			mm1=x1.m2;
		}
		else{
			mm1=x1.m3;
		}
		if(x2.m2>x2.m3){
			mm1=x2.m2;
		}
		else{
			mm1=x2.m3;
		}
	}
	if(ss2){
		mm2=x1.m2,mm4=x2.m2;
		if(x1.m1>x1.m3){
			mm1=x1.m1;
		}
		else{
			mm1=x1.m3;
		}
		if(x2.m1>x2.m3){
			mm1=x2.m1;
		}
		else{
			mm1=x2.m3;
		}
	}
	if(ss3){
		mm2=x1.m3,mm4=x2.m3;
		if(x1.m2>x1.m1){
			mm1=x1.m2;
		}
		else{
			mm1=x1.m1;
		}
		if(x2.m2>x2.m1){
			mm1=x2.m2;
		}
		else{
			mm1=x2.m1;
		}
	}
	if((mm1-mm2)>(mm3-mm4)){
		return true;
	}
	else return false;
}
bool co2(node x1,node x2){
	if(x1.ok1>x2.ok1) return true;
	else return false;
}
bool co1(node x1,node x2){
	if(x1.ok1<x2.ok1) return true;
	else return false;
}
//vector<node> o;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	for(int pq=1;pq<=t;pq++){
		cin>>n;
		a1=a11=a2=a22=a3=a33=0;
		ss1=ss2=ss3=0;
		f1=f2=f3=0;
		for(int i=1;i<=n;i++){
			cin>>o[i].m1>>o[i].m2>>o[i].m3;
			o[i].n1=i;
			o[i].ok1=o[i].m1-o[i].m2;
			o[i].ok2=o[i].m2-o[i].m3;
			if(o[i].m1!=0) f1=1;
			if(o[i].m2!=0) f2=1;
			if(o[i].m3!=0) f3=1;
			if(o[i].m1>=o[i].m2&&o[i].m1>=o[i].m3){
				a1++,a11+=o[i].m1;
			}
			else if(o[i].m2>=o[i].m1&&o[i].m2>=o[i].m3){
				a2++,a22+=o[i].m2;
			}
			else{
				a3++,a33+=o[i].m3;
			}
		}
		if(a1<=n/2&&a2<=n/2&&a3<=n/2){
			cout<<a11+a22+a33<<endl;
			continue;
		}
		ss1=(a1>n/2?a1-(n/2):0);
		ss2=(a2>n/2?a2-(n/2):0);
		ss3=(a3>n/2?a3-(n/2):0);
		//if(pq==2){
		//	cout<<a1<<" "<<a2<<" "<<a3<<endl;
		//}
		if(f1==f3&&f3==0){
			sort(o+1,o+n,compare2);
			for(int i=1;i<=ss2;++i){
				a22-=o[i].m2;
			}
			cout<<a22<<endl;
			continue;
		}
		if(f3==0){
			if(ss1>0){
				sort(o+1,o+1+n,co1);
				long long se=0;
				se=a22+a11;
				for(int i=a2+1;i<=a2+ss1;++i){
					se-=o[i].ok1;
				}
				cout<<se<<endl;
				continue;
			}
			if(ss2>0){
				sort(o+1,o+1+n,co2);
				long long se=0;
				se=a11+a22;
				for(int i=a1+1;i<=a1+ss2;++i){
					se+=o[i].ok1;
				}
				cout<<se<<endl;
			}
			continue;
		}
		if(n==2){
			long long se,max1=0;
			for(int i=1;i<=3;++i){
				for(int j=1;j<=3;++j){
					se=0;
					if(i==j) continue;
					if(i==1) se+=o[1].m1;
					if(i==2) se+=o[1].m2;
					if(i==3) se+=o[1].m3;
					if(j==1) se+=o[2].m1;
					if(j==2) se+=o[2].m2;
					if(j==3) se+=o[2].m3;
					//cout<<i<<" "<<j<<" "<<se<<" "<<max1<<endl;
					max1=se>max1?se:max1;
				}
			}
			cout<<max1<<endl;
			continue;
		}
		if(n==4){
			long long se,max1=0,xxx;
			bool ff1=0,ff2=0,ff3=0;
			for(int i=1;i<=3;++i){
				for(int j=1;j<=3;++j){
					if(i==j){
						++xxx;
						ff1=1;
					}
					for(int k=1;k<=3;++k){
						if(k==i||k==j){
							++xxx;
							ff2=1;
						}
						if(xxx==2){
							--xxx;
							ff2=0;
							continue;
						}
						for(int l=1;l<=3;++l){
							se=0;
							if(l==i||l==j||l==k){
								++xxx;
								ff3=1;
							}
							if(xxx==2){
								--xxx;
								ff3=0;
								continue;
							}
					if(i==1) se+=o[1].m1;
					if(i==2) se+=o[1].m2;
					if(i==3) se+=o[1].m3;
					if(j==1) se+=o[2].m1;
					if(j==2) se+=o[2].m2;
					if(j==3) se+=o[2].m3;
					if(k==1) se+=o[3].m1;
					if(k==2) se+=o[3].m2;
					if(k==3) se+=o[3].m3;
					if(l==1) se+=o[4].m1;
					if(l==2) se+=o[4].m2;
					if(l==3) se+=o[4].m3;
					max1=se>max1?se:max1;
							if(ff3){
								--xxx;
								ff3=0;
							}
						}
						if(ff2){
							--xxx;
							ff2=0;
						}
					}
					if(ff1){
						--xxx;
						ff1=0;
					}
				}
			}
			cout<<max1<<endl;
			continue;
		}
		if(ss1!=0){
			sort(o+1,o+n,cc1);
			long long se=a11+a22+a33;
			for(int i=a2+a3+1;i<=n;++i){
				if(o[i].m2>o[i].m3){
					se-=o[i].m1;
					se+=o[i].m2;
				}
				else{
					se-=o[i].m1;
					se+=o[i].m3;
				}
			}
			cout<<se<<endl;
		}
		if(ss2!=0){
			sort(o+1,o+n,cc1);
			long long se=a11+a22+a33;
			for(int i=a1+a3+1;i<=n;++i){
				if(o[i].m1>o[i].m3){
					se-=o[i].m2;
					se+=o[i].m1;
				}
				else{
					se-=o[i].m2;
					se+=o[i].m3;
				}
			}
			cout<<se<<endl;
		}
		if(ss3!=0){
			sort(o+1,o+n,cc1);
			long long se=a11+a22+a33;
			for(int i=a1+a2+1;i<=n;++i){
				if(o[i].m1>o[i].m2){
					se-=o[i].m3;
					se+=o[i].m1;
				}
				else{
					se-=o[i].m3;
					se+=o[i].m2;
				}
			}
			cout<<se<<endl;
		}
	}
	return 0;
}
