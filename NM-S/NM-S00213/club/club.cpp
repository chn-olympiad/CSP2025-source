#include<bits/stdc++.h>
using namespace std;
//struct stu{
//	short as;
//	short bs;
//	short cs;
//	int a;
//	int b;
//	int c;
//};
//bool cmp(const stu& a,const stu& b){
//	if(a.as==1){
//		
//	}
//}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t=0;
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		int n=0,cnt=0;
		scanf("%d",&n);
		int a=0,b=0,c=0;
		for(int j=0;j<n;j++){
			int q=0;
			scanf("%d%d%d",&a,&b,&c);
			q=max(a,max(b,c));
			cnt+=q;
		}
		printf("%d\n",cnt);
		//int nf=n/2;
	}
//		int stu[1005][5]={};
//		vector<stu>vec(n);
//		for(int j=0;j<n;j++){
//			for(int k=0;k<3;k++){
//				scanf("%d",&stu[j][k]);
//			}
//		}
	return 0; 
}
//#include<bits/stdc++.h>
//using namespace std;
////struct stu{
////	short as;
////	short bs;
////	short cs;
////	int a;
////	int b;
////	int c;
////};
////bool cmp(const stu& a,const stu& b){
////	if(a.as==1){
////		
////	}
////}
//int main(){
//	//freopen("club.in","r",stdin);
//	//freopen("club.out","w",stdout);
//	int t=0;
//	scanf("%d",&t);
//	for(int i=0;i<t;i++){
//		int n=0,cnt=0;
//		scanf("%d",&n);
//		int nf=n/2; 
//		int stu[1005][5]={};
////		vector<stu>vec(n);
//		for(int j=0;j<n;j++){
//			for(int k=0;k<3;k++){
//				scanf("%d",&stu[j][k]);
//			}
//		}
//		int zong=0;
//		for(int k=0;k<3;k++){
//			for(int ja=0;ja<n;ja++){
//				for(int ka=0;ka<n;ka++){
//					for(int qa=0;qa<3;qa++){
////						if(ka==k){
////							continue;
////						}
////						cout<<ka<<' '<<ka<<' ';
//						cout<<k<<' '<<ja<<' '<<ka<<' '<<qa<<'\n';
//					}cout<<'\n';
//				}
//				
//			}	
//		}
//	}
//	return 0; 
//}
////1
////6
////1 2 3
////1 3 2 
////2 1 3 
////2 3 1 
////3 1 2
////3 2 1 
////#include<bits/stdc++.h>
////using namespace std;
////struct stu{
////	short as;
////	short bs;
////	short cs;
////	int a;
////	int b;
////	int c;
////};
//////bool cmp(const stu& a,const stu& b){
//////	if(a.as==1){
//////		
//////	}
//////}
////int main(){
////	//freopen("club.in","r",stdin);
////	//freopen("club.out","w",stdout);
////	int t=0;
////	scanf("%d",&t);
////	for(int i=0;i<t;i++){
////		int n=0,cnt=0;
////		scanf("%d",&n);
////		int nf=n/2; 
////		vector<stu>vec(n);
////		for(int j=0;j<n;j++){
////			scanf("%d%d%d",&vec[j].a,&vec[j].b,&vec[j].c);
////			if(vec[j].a>vec[j].b&&vec[j].a>vec[j].c){
////				vec[j].as=1;
////				if(vec[j].b>vec[j].c){
////					vec[j].bs=2;
////					vec[j].cs=3;
////				}else{
////					vec[j].bs=3;
////					vec[j].cs=2;
////				}
////			}else if(vec[j].b>vec[j].c){
////				vec[j].bs=1;
////				if(vec[j].c>vec[j].a){
////					vec[j].cs=2;
////					vec[j].as=3;
////				}else{
////					vec[j].cs=3;
////					vec[j].as=2;
////				}
////			}else{	
////				vec[j].cs=1;
////				if(vec[j].a>vec[j].b){
////					vec[j].as=2;
////					vec[j].bs=3;
////				}else{
////					vec[j].as=3;
////					vec[j].bs=2;
////				}	
////			}
////			
////		}
////		
//////		sort(vec.begin(),vec.end(),cmp);
////		int ac=0,bc=0,cc=0;
////		for(int j=0;j<n;j++){
////			
//////			cout<<j<<":\n"<<"a:"<<vec[j].as<<' '<<vec[j].a<<" b:"<<vec[j].bs<<' '<<vec[j].b<<" c:"<<vec[j].cs<<' '<<vec[j].c<<'\n';
////		}
////	}
////	return 0; 
////}
//////1
//////6
//////1 2 3
//////1 3 2 
//////2 1 3 
//////2 3 1 
//////3 1 2
//////3 2 1 
//3
//4
//4 2 1
//3 2 4
//5 3 4
//3 5 1
//4
//0 1 0
//0 1 0
//0 2 0
//0 2 0
//2
//10 9 8
//4 0 0
