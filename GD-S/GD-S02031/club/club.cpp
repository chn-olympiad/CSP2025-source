#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int t,n;
int a12[N],a13[N],a23[N],sum,ans1,ans2,ans3;
int id1,id2,id3,idx;
bool is[N];
struct a1{
	int zhi,quan;
}a1[N];
struct a2{
	int zhi,quan;
}a2[N];
struct a3{
	int zhi,quan;
}a3[N];
void find(){
	int max1=0,max2=0,max3=0,maxx=0;
	for(int i=1;i<=n;i++){
		if(is[i]==false){
			if(max1<a1[i].quan&&ans1<n/2){
				max1=a1[i].quan;
				id1=i;
			}else if(max1<a1[i].quan&&ans1>=n/2){
				id1=i;
			}
			if(max2<a2[i].quan&&ans2<n/2){
				max2=a2[i].quan;
				id2=i;
			}else if(max2<a2[i].quan&&ans2>=n/2){
				id2=i;
			}
			if(max3<a3[i].quan&&ans3<n/2){
				max3=a3[i].quan;
				id3=i;
			}else if(max3<a3[i].quan&&ans3>=n/2){
				id3=i;
			}
		}
	}
	//cout<<id1<<" "<<id2<<" "<<id3<<endl; 
	//cout<<max1<<" "<<max2<<" "<<max3<<endl;
	if(max1>=max2&&max1>=max3){
		
		if(max1==max2){
			if(a1[id1].zhi>a2[id1].zhi){
				sum+=a1[id1].zhi;
				is[id1]=true;
				ans1++;
			}else {
				sum+=a2[id2].zhi;
				is[id2]=true;
				ans2++;
			}
		}else if(max1==max3){
			if(a1[id1].zhi>a3[id1].zhi){
				sum+=a1[id1].zhi;
				is[id1]=true;
				ans1++;
			}else{sum+=a3[id3].zhi;
				is[id3]=true;
				ans3++;
			}
		}else{
			sum+=a1[id1].zhi;
			is[id1]=true;
			ans1++;
		}
	}else if(max2>=max3&&max2>=max1){
		if(max1==max2){
			if(a1[id1].zhi>a2[id1].zhi){
				sum+=a1[id1].zhi;
				is[id1]=true;
				ans1++;
			}else {
				sum+=a2[id2].zhi;
				is[id2]=true;
				ans2++;
			}
		}else if(max2==max3){
			if(a2[id2].zhi>a3[id2].zhi){
				sum+=a2[id2].zhi;
				is[id2]=true;
				ans2++;
			}else {
				is[id3]=true;sum+=a3[id3].zhi;
				ans3++;
			}
		}else{
			sum+=a2[id2].zhi;
			is[id2]=true;
			ans2++;
		}
	}else{
		
		if(max1==max3){
			if(a1[id1].zhi>a3[id1].zhi){
				sum+=a1[id1].zhi;
				is[id1]=true;
				ans1++;
			}else{
				sum+=a3[id3].zhi;
				is[id3]=true;
				ans3++;
			}
		}else if(max2==max3){
			if(a2[id2].zhi>a3[id2].zhi){
				sum+=a2[id2].zhi;
				is[id2]=true;
				ans2++;
			}else {
				sum+=a3[id3].zhi;is[id3]=true;
				ans3++;
			}
		}else{
			sum+=a3[id3].zhi;
			is[id3]=true;
			ans3++;
		}
	}
	//cout<<ans1<<" "<<ans2<<" "<<ans3<<endl;
	//cout<<endl<<sum<<endl;
}
int main(){
	cin>>t;
	while(t--){
		sum=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a1[i].zhi>>a2[i].zhi>>a3[i].zhi;
			if(a1[i].zhi>a2[i].zhi)a12[i]=a1[i].zhi-a2[i].zhi;
			else a12[i]=a2[i].zhi-a1[i].zhi;
			if(a1[i].zhi>a3[i].zhi)a13[i]=a1[i].zhi-a3[i].zhi;
			else a13[i]=a3[i].zhi-a1[i].zhi;
			if(a3[i].zhi>a2[i].zhi)a23[i]=a3[i].zhi-a2[i].zhi;
			else a23[i]=a2[i].zhi-a3[i].zhi;
		}
		for(int i=1;i<=n;i++){
			a1[i].quan=a12[i]+a13[i];
			a2[i].quan=a12[i]+a23[i];
			a3[i].quan=a13[i]+a23[i];
			//cout<<a1[i].quan<<" "<<a2[i].quan<<" "<<a3[i].quan<<endl;
		}
		for(int i=1;i<=n;i++){
			find();
		}
		cout<<sum<<endl;
		
	}
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	return 0;
} 
