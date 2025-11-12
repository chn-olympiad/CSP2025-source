#include<bits/stdc++.h>
using namespace std;
long long t,n,id1[50010],id2[50010],id3[50010],ans1,ans2,ans3,temp1,temp2,temp3,anss;
struct st{
	long long a1,a2,a3;
}a[100010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans1=0;
		ans2=0;
		ans3=0;
		memset(id1,0,sizeof id1);
		memset(id2,0,sizeof id2);
		memset(id3,0,sizeof id3);
		memset(a,0,sizeof a);
		for(int i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			int maxs=max(a[i].a1,max(a[i].a2,a[i].a3));
			if(maxs==a[i].a1){
				if(ans1<n/2){
					id1[++ans1]=i;
				}else{
					bool flag=false;
					int soc=0,idcard=0;
					for(int j=1;j<=ans1;j++){
						temp1=a[id1[j]].a1,temp2=a[id1[j]].a2,temp3=a[id1[j]].a3;
						if(temp1+max(a[i].a2,a[i].a3)<a[i].a1+max(temp2,temp3)){
							if(soc<a[i].a1+max(temp2,temp3)-(temp1+max(a[i].a2,a[i].a3))){
								soc=a[i].a1+max(temp2,temp3)-(temp1+max(a[i].a2,a[i].a3));
								idcard=j;
								flag=true;
							}
						}
					}
					if(flag==false){
						if(a[i].a2>a[i].a3) id2[++ans2]=i;
						else id3[++ans3]=i;
					}else{
						if(a[id1[idcard]].a2>a[id1[idcard]].a3){
								id2[++ans2]=id1[idcard];
							}else{
								id3[++ans3]=id1[idcard];
						}
						id1[idcard]=i;
					}
				}
			}else if(maxs==a[i].a2){
				if(ans2<n/2){
					id2[++ans2]=i;
				}else{
					bool flag=false;
					int soc=0,idcard=0;
					for(int j=1;j<=ans2;j++){
						temp1=a[id2[j]].a1,temp2=a[id2[j]].a2,temp3=a[id2[j]].a3;
						if(temp2+max(a[i].a1,a[i].a3)<a[i].a2+max(temp1,temp3)){
							if(soc<a[i].a2+max(temp1,temp3)-(temp2+max(a[i].a1,a[i].a3))){
								soc=a[i].a2+max(temp1,temp3)-(temp2+max(a[i].a1,a[i].a3));
								idcard=j;
								flag=true;
							}
							
						}
					}
					if(flag==false){
						if(a[i].a1>a[i].a3) id1[++ans1]=i;
						else id3[++ans3]=i;
					}else{
						if(a[id2[idcard]].a1>a[id2[idcard]].a3){
								id1[++ans1]=id2[idcard];
						}else{
								id3[++ans3]=id2[idcard];
						}
						id2[idcard]=i;
					}
				}
			}else if(maxs==a[i].a3){
				if(ans3<n/2){
					id3[++ans3]=i;
				}else{
					bool flag=false;
					int soc=0,idcard=0;
					for(int j=1;j<=ans3;j++){
						temp1=a[id3[j]].a1,temp2=a[id3[j]].a2,temp3=a[id3[j]].a3;
						if(temp3+max(a[i].a1,a[i].a2)<a[i].a3+max(temp1,temp2)){
							if(soc<a[i].a3+max(temp1,temp2)-(temp3+max(a[i].a1,a[i].a2))){
								soc=a[i].a3+max(temp1,temp2)-(temp3+max(a[i].a1,a[i].a2));
								idcard=j;
								flag=true;
							}
							
						}
					}
					if(flag==false){
						if(a[i].a1>a[i].a2) id1[++ans1]=i;
						else id2[++ans2]=i;
					}else{
						if(a[id3[idcard]].a1>a[id3[idcard]].a2){
								id1[++ans1]=id3[idcard];
							}else{
								id2[++ans2]=id3[idcard];
							}
							id3[idcard]=i;
					}
				}
			}
		}
		long long sum=0;
		for(int i=1;i<=ans1;i++){
			sum+=a[id1[i]].a1;
		}
		for(int i=1;i<=ans2;i++){
			sum+=a[id2[i]].a2;
		}
		for(int i=1;i<=ans3;i++){
			sum+=a[id3[i]].a3;
		}
		cout<<sum<<endl;
	
	}
	return 0;
}
