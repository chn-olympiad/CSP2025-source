#include<bits/stdc++.h>
using namespace std;
struct zz{
	int a;
	int b;
	int c;
}a[100008];
bool cmp1(zz x,zz y){
	return x.a>y.a;
}
bool cmp2(zz x,zz y){
	return x.b>y.b;
}
bool cmp3(zz x,zz y){
	return x.c>y.c;
}
struct nd{
	int a;
	int b;
};
bool cmm(nd x,nd y){
	return x.a>x.a;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		bool pd1=1,pd2=1,pd3=1;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			if(a[i].c!=0){
				pd3=0;
			}
			if(a[i].b!=0){
				pd2=0;
			}
			if(a[i].a!=0){
				pd1=0;
			}
		}
		//cout<<pd1<<" "<<pd2<<" "<<pd3<<endl;
		if(pd2&&pd3){
			long long yanruotong=0;
			sort(a+1,a+n+1,cmp1);
			for(int i=1;i<=n/2;i++){
				yanruotong+=a[i].a;
			}
			cout<<yanruotong<<endl;
			continue;
		}
		if(pd1&&pd3){
			long long yanruotong=0;
			sort(a+1,a+n+1,cmp2);
			for(int i=1;i<=n/2;i++){
				yanruotong+=a[i].b;
			}
			cout<<yanruotong<<endl;
			continue;
		}
		if(pd1&&pd2){
			long long yanruotong=0;
			sort(a+1,a+n+1,cmp3);
			for(int i=1;i<=n/2;i++){
				yanruotong+=a[i].c;
			}
			cout<<yanruotong<<endl;
			continue;
		}
		
		
				
		int ct[3]={0,0,0};
		int ans=0;
		for(int i=1;i<=n;i++){
			 nd bb[4];
			 bb[1].a=a[i].a;
			 bb[2].a=a[i].b;
			 bb[3].a=a[i].c;
			 for(int j=1;j<=3;j++)bb[j].b=j;
			 sort(bb+1,bb+4,cmm);
			 for(int j=1;j<=3;j++){
			 	if(ct[bb[j].b]<n/2){
			 		ct[bb[j].b]++;
			 		ans+=bb[j].a;
			 		break;
				 }
			 }
			 
		}
		cout<<ans<<endl;
	
	}
	return 0;
}



//#include<bits/stdc++.h>
//using namespace std;
//struct zz{
//	int a;
//	int b;
//	int c;
//}a[100008];
//bool cmp(zz a,zz b){
//	return max(a.a,max(a.b,a.c))>max(b.a,max(b.b,b.c));
//}
//struct nd{
//	int a;
//	int b;
//};
//bool cmm(nd x,nd y){
//	return x.a>x.a;
//}
//int main(){
////	freopen("C:\\Users\\student\\Desktop\\down\\club\\club4.in","r",stdin);
////	freopen("club.out","w",stdout);
//	int t;
//	cin>>t;
//	while(t--){
//		int n;
//		cin>>n;
//		for(int i=1;i<=n;i++){
//			cin>>a[i].a>>a[i].b>>a[i].c;
//		}
//		int ct[3]={0,0,0};
//		int ans=0;
//		for(int i=1;i<=n;i++){
//			 nd bb[4];
//			 bb[1].a=a[i].a;
//			 bb[2].a=a[i].b;
//			 bb[3].a=a[i].c;
//			 for(int j=1;j<=3;j++)bb[j].b=j;
//			 sort(bb+1,bb+4,cmm);
//			 for(int j=1;j<=3;j++){
//			 	if(ct[bb[j].b]<n/2){
//			 		ct[bb[j].b]++;
//			 		ans+=bb[j].a;
//			 		break;
//				 }
//			 }
//			 
//		}
//		cout<<ans<<endl;
//	}
//	return 0;
//}

