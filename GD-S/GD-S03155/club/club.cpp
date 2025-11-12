#include<bits/stdc++.h>
using namespace std;
long long t=0;//测试组数
long long in[100005];//满意度 
long long p1[100005];//对a部门的满意度在三个中的排序 3最大1最小 
long long p2[100005];//对b部门的满意度在三个中的排序 3最大1最小
long long p3[100005];//对c部门的满意度在三个中的排序 3最大1最小

long long in1[100005];//部门1的满意度 
long long in2[100005];//部门2的满意度 
long long in3[100005];//部门3的满意度 

long long ol1[100005];//部门1的满意度 
long long ol2[100005];//部门2的满意度 
long long ol3[100005];//部门3的满意度 

long long ch1[100005];//部门1超出的人数的编号 
long long ch2[100005];//部门2超出的人数的编号 
long long ch3[100005];//部门3超出的人数的编号

long long ans1;
long long ans2;
long long ans3;
long long ansp[3];

long long n=0;//新成员的数量

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
//	long long T=t;
	while(t--){
		memset(in1,0,sizeof(in1));//初始化为0
		memset(in2,0,sizeof(in2));
		memset(in3,0,sizeof(in3));
		memset(p1,0,sizeof(p1));
		memset(p2,0,sizeof(p2));
		memset(p3,0,sizeof(p3));
		memset(ol1,0,sizeof(ol1));
		memset(ol2,0,sizeof(ol2));
		memset(ol3,0,sizeof(ol3));
		memset(ch1,0,sizeof(ch1));
		memset(ch2,0,sizeof(ch2));
		memset(ch3,0,sizeof(ch3));
		
		ans1=0;
		ans2=0;
		ans3=0;
		
		cin>>n;
		
		for(int i=1;i<=n;i++){
			int a,b,c;
			cin>>a>>b>>c;//每个成员对每个部门的满意度
			if(a>=b && a>=c && b>=c){//a=>b=>c 
				p1[i]=i*10+3;//a         3>2>1
				p2[i]=i*10+2;//b
				p3[i]=i*10+1;//c
			}
			if(a>=b && a>=c && c>=b){//a>=c>=b 
				p1[i]=i*10+3;
				p2[i]=i*10+1;
				p3[i]=i*10+2; 
			}
			if(b>=a && b>=c && a>=c){//b>=a>=c 
				p1[i]=i*10+2;
				p2[i]=i*10+3;
				p3[i]=i*10+1; 
			}
			if(b>=a && b>=c && c>=a){//b>=c>=a 
				p1[i]=i*10+1;
				p2[i]=i*10+3;
				p3[i]=i*10+2; 
			}
			if(c>=a && c>=b && a>=b){//c>=a>=b 
				p1[i]=i*10+2;
				p2[i]=i*10+1;
				p3[i]=i*10+3; 
			}
			if(c>=a && c>=b && b>=a){//c>=b>=a
				p1[i]=i*10+1;
				p2[i]=i*10+2;
				p3[i]=i*10+3; 
			}
			ol1[i]=a*100+b*10+c;
			ol2[i]=b*10+c;
			ol3[i]=c;
			in1[i]=a;//部门1的满意度
			in2[i]=b;//部门2的满意度
			in3[i]=c;//部门3的满意度
		}
		
//		long long ma1=0;
//		long long ma2=0;
//		for(int i=1;i<=n;i++){
//			if(in1[i]==0){
//				ma1++;
//			}
//			if(in2[i]==0){
//				ma2++;
//			}	
//		} 
//		if(ma1==n&&ma2==n){
//			sort(in2,in2+n+1);
//				int pp=0;
//				for(int i=n/2;i<=n;i++){
//					pp+=in2[i];
//				}	
//			
//			cout<<0<<endl<<pp<<endl<<0<<endl;
//		}

		int k1=0,k2=0,k3=0;
		for(int i=1;i<=n;i++){
			if(p1[i]%10==3){
				k1++;
				ans1+=in1[i];
			}
			if(p2[i]%10==3){
				k2++;
				ans2+=in2[i];
			}
			if(p3[i]%10==3){
				k3++;
				ans3+=in3[i];
			}
		}
		if(k1<=n/2 && k2<=n/2 && k3<=n/2 && k1+k2+k3==n){
			cout<<ans1+ans2+ans3<<endl;
		}
		else{
			if(k1>n/2){
				sort(ol1,ol1+n+1);
				for(int i=1;i<=k1-n/2;i++){
					ch1[i]=ol1[i];
					ans1-=ol1[i]/100;
				}
				k1=n/2;
			}
			if(k2>n/2){
				sort(ol2,ol2+n+1);
				for(int i=1;i<=k2-n/2;i++){
					ch2[i]=ol2[i];
					ans2-=(ol2[i]-ol2[i]/100*100)/10;
				}		
				k2=n/2;
			
			}
			if(k3>n/2){
				sort(ol3,ol3+n+1);
				for(int i=1;i<=k3-n/2;i++){
					ch3[i]=ol3[i];
					ans3-=ol3[i]-(ol3[i]-ol3[i]/100*100)/10*10;
				}		
			
			}
		}			
			
	}
	
	
	return 0;
}
