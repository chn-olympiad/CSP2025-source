#include<bits/stdc++.h>
using namespace std;
int n,T;
int sum;
int cnt1,cnt2,cnt3;
const int N=1e5+55;
int MAX[N];
int d[N];
int flag[N];
int max2[N];
int cnt11[N];
int cnt22[N];
int cnt33[N];
int ccnt1[N];
int ccnt2[N];
int ccnt3[N];
struct node{
	int x,y,z;
	int flag;
}q[N];
int p[N];
int main(){
	int i1=1,i2=1,i3=1;
	cin >> T;
	while(T--){
		cin >> n;
		for(int i=1;i<=n;i++){
			cin >>q[i].x >>q[i].y >>q[i].z;
			//int x,y,z;
			//cin >> x >> y >> z;
			int l=max(max(q[i].x,q[i].y),q[i].z);
			if(l==q[i].x){
				flag[i]=1;
				max2[i]=max(q[i].y,q[i].z);
			}
			if(l==q[i].y){
				flag[i]=2;
				max2[i]=max(q[i].x,q[i].z);
			}
			if(l==q[i].z){
				flag[i]=3;
				max2[i]=max(q[i].x,q[i].y);
			}
			MAX[i]=l;
			p[MAX[i]]=flag[i];
			d[MAX[i]]=max2[i];
		}
		sort(MAX+1,MAX+n+1);
		for(int i=1;i<=n;i++){
			sum+=MAX[i];
		}
		//for(int i=1;i<=n;i++){
		//	cout << p[MAX[i]]<<" " <<d[MAX[i]] <<MAX[i]<<" " << endl;
		//}
		//cout <<sum;
		int nn=n/2;
		for(int i=1;i<=n;i++){
			//cout << p[MAX[i]];
			if(p[MAX[i]]==1){
				cnt1++;
				cnt11[i1]=MAX[i];
				i1++;
			}
			if(p[MAX[i]]==2){
				cnt2++;
				cnt22[i2]=MAX[i];
				i2++;
			}
			if(p[MAX[i]]==3){
				cnt3++;
				cnt33[i3]=MAX[i];
				i3++;
			}
		} 
		//cout << cnt3;
		//for(int i=1;i<=cnt2;i++){
			//cout << cnt22[i];
		//}
		if(cnt1>nn){
			int cha1=cnt1-nn;
			for(int i=1;i<=cnt1;i++){
				ccnt1[i]=cnt11[i]-d[cnt11[i]];	
			}
			sort(ccnt1+1,ccnt1+cnt1+1);
			for(int i=1;i<=cha1;i++){
				sum-=ccnt1[i];
			}
			cout <<sum << endl;
			cnt1=0;sum=0;cha1=0;nn=0;
			//cout << 1;
			//cout << cha1;
		}
		if(cnt2>nn){
			int cha2=cnt2-nn;
			for(int i=1;i<=cnt2;i++){
				ccnt2[i]=cnt22[i]-d[cnt22[i]];	
			}
			sort(ccnt2+1,ccnt2+cnt2+1);
			//for(int i=1;i<=cnt2;i++){
				//cout << ccnt2[i]<< endl;
			//}
			for(int i=1;i<=cha2;i++){
				sum-=ccnt2[i];
			}
			cout <<sum << endl;
			cnt2=0;sum=0;cha2=0;nn=0;
			sum=0;
			//cout << 2;
			//cout <<cha2;
		}
		if(cnt3>nn){
			int cha3=cnt3-nn;
			for(int i=1;i<=cnt3;i++){
				ccnt3[i]=cnt33[i]-d[cnt33[i]];	
			}
			sort(ccnt3+1,ccnt3+cnt3+1);
			for(int i=1;i<=cha3;i++){
				sum-=ccnt3[i];
			}
			cout <<sum << endl;
			cnt3=0;sum=0;cha3=0;nn=0;
			
			//cout <<3;
			//cout << cha3;
		}
		//cout <<cnt1 << cnt2 << cnt3;
	}
}
