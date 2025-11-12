#include<bits/stdc++.h>
using namespace std;

struct s{
	int a,b,c,d;
}stu[100005];

bool cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		int sum=0,max=0;
		int d1=0,d2=0,d3=0;
		if(n>=100000){
			int aa[n+1];
			for(int i=0;i<n;i++){
				cin>>stu[i].a>>stu[i].b>>stu[i].c;
				aa[i]=stu[i].a;
			}
			sort(aa,aa+n,cmp);
			for(int i=0;i<n/2;i++){
				sum+=aa[i];
			}
		}
		else{
		for(int i=0;i<n;i++){
			cin>>stu[i].a>>stu[i].b>>stu[i].c;
			max=stu[i].a;
			stu[i].d=1;
			d1++;
			if(max<stu[i].b){
				max=stu[i].b;
				stu[i].d=2;
				d2++;
				d1--;
			}
			if(max<stu[i].c){
				max=stu[i].c;
				if(stu[i].d==1){
					d1--;
				}
				else{
					d2--;
				}
				stu[i].d=3;
				d3++;
			}
			sum+=max;
		}
		while(d1>n/2 || d2>n/2 || d3>n/2){
			while(d1>n/2){
				int mins=200001,flag=0,bf=2;
				for(int i=0;i<n;i++){
					if(stu[i].d==1){
						int cha=stu[i].a-stu[i].b;
						int sf=2;
						if(stu[i].a-stu[i].c<cha){
							cha=stu[i].a-stu[i].c;
							sf=3;
						}
						if(cha<mins){
							mins=cha;
							flag=i;
							bf=sf;
						}
					}
					else continue;
				}
				sum-=mins;
				stu[flag].d=bf;
				d1--;
				if(bf==2){
					d2++;
				}
				else d3++;
			}
			while(d2>n/2){
				int mins=200001,flag=0,bf=1;
				for(int i=0;i<n;i++){
					if(stu[i].d==2){
						int cha=stu[i].b-stu[i].a;
						int sf=1;
						if(stu[i].b-stu[i].c<cha){
							cha=stu[i].b-stu[i].c;
							sf=3;
						}
						if(cha<mins){
							mins=cha;
							flag=i;
							bf=sf;
						}
					}
					else continue;
				}
				sum-=mins;
				stu[flag].d=bf;
				d2--;
				if(bf==1){
					d1++;
				}
				else d3++;
			}
			while(d3>n/2){
				int mins=200001,flag=0,bf=1;
				for(int i=0;i<n;i++){
					if(stu[i].d==3){
						int cha=stu[i].c-stu[i].a;
						int sf=1;
						if(stu[i].c-stu[i].b<cha){
							cha=stu[i].c-stu[i].b;
							sf=2;
						}
						if(cha<mins){
							mins=cha;
							flag=i;
							bf=sf;
						}
					}
					else continue;
				}
				sum-=mins;
				stu[flag].d=bf;
				d3--;
				if(bf==1){
					d1++;
				}
				else d2++;
			}
		}
			
		}
		cout<<sum<<'\n';
	}
	
	return 0;
}
