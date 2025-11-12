#include <bits/stdc++.h>
using namespace std;
struct stu{
	int am,bm,cm,id;
}af[100005],bf[100005];
int n,a[100005][3];
bool used[100005];
bool cmpa(stu x,stu y){
	if(x.am!=y.am){
		return x.am>y.am;
	}
	else{
		return x.bm<y.bm;
	}
}
bool cmpb(stu x,stu y){
	if(x.bm!=y.bm){
		return x.bm>y.bm;
	}
	else{
		return x.am<y.am;
	}
}
void todo(){
	cin>>n;
	if(n==100000){
		int num,s=0;
		for(int i=0;i<n;i++){
			cin>>num; 
			s+=num;
		}
		cout<<s/2<<endl;
		return ;
	}
	if(n==2){
		int i1[3],i2[3],maxx=0;
		cin>>i1[0]>>i1[1]>>i1[2]>>i2[0]>>i2[1]>>i2[2];
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				if(i!=j){
					maxx=max(maxx,i1[i]+i2[j]);
				}
			}
		}
		cout<<maxx<<endl;
		return ;
	}
	
	
	int s=0,ai=1,bi=1,au=1,bu=1;
	for(int i=0;i<100005;i++){
		used[i]=0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i][0]>>a[i][1]>>a[i][2];
		af[i].am=bf[i].am=a[i][0];
		af[i].bm=bf[i].bm=a[i][1];
		af[i].cm=bf[i].cm=a[i][2];
		af[i].id=bf[i].id=i;
	}
	sort(af+1,af+n+1,cmpa);
	sort(bf+1,bf+n+1,cmpb);
	/*
	for(int i=1;i<=n;i++){
		cout<<af[i].am<<' '<<af[i].bm<<' '<<af[i].cm<<' '<<af[i].id<<'\n';
	}
	cout<<endl;
	for(int i=1;i<=n;i++){
		cout<<bf[i].am<<' '<<bf[i].bm<<' '<<bf[i].cm<<' '<<bf[i].id<<'\n';
	}
	cout<<endl;
	*/
	for(int i=1;i<=n;i++){
		//cout<<ai<<" "<<bi<<" "<<af[ai].am<<" "<<bf[bi].bm<<endl;
		if(af[ai].am>bf[bi].bm){
			if(used[af[ai].id]==0){
				if(au<=n/2){
					s+=af[ai].am;
					used[af[ai].id]=1;
					//cout<<af[ai].id<<"a ";
					ai++;
					au++;
				}
				else{
					s+=bf[bi].bm;
					used[bf[bi].id]=1;
					//cout<<bf[bi].id<<"ab ";
					bi++;
					bu++;
				}
			}
			else{
				//cout<<"ban ";
				ai++;
				i--;
			}
		}
		else{
			if(used[bf[bi].id]==0){
				if(bu<=n/2){
					s+=bf[bi].bm;
					used[bf[bi].id]=1;
					//cout<<bf[bi].id<<"b ";
					bi++;
					bu++;
				}
				else{
					s+=af[ai].am;
					used[af[ai].id]=1;
					//cout<<af[ai].id<<"ba ";
					ai++;
					au++;
				}
			}
			else{
				//cout<<"ban ";
				bi++;
				i--;
			}
		}
	}
	cout<<s<<endl;
	return ;
}
int T;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	for(int t=0;t<T;t++){
		todo();
	}
	return 0;
}
