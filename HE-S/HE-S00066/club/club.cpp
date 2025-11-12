#include<bits/stdc++.h>
using namespace std;
const int INF=1e5+10; 
struct newclub{
	//ÂúÒâ¶ÈABC 
	int mydA,mydB,mydC,sum;
}a[INF],b[INF];
int T,n;
bool cmp(newclub qwe,newclub ewq){
	return qwe.sum<ewq.sum;
}
bool cmp1(newclub qwe,newclub ewq){
	return qwe.sum>ewq.sum;
}
int ccz(int s,int e,int c){
	int maxn=max(s,max(e,c));
	if(maxn==s){
		return 1;
	}else if(maxn==e){
		return 2;
	}else{
		return 3;
	}
}
int czz(int s,int e,int c){
	int maxn=max(s,max(e,c));
	int qe;
	if(maxn==s){
	    qe=ccz(-1,e,c);
	}else if(maxn==e){
		qe=ccz(s,-1,c);
	}else{
		qe=ccz(s,e,-1);
	}
	return qe;
}
int whicha(int s,int i){
	if(s==1){
		return a[i].mydA;
	}else if(s==2){
		return a[i].mydB;
	}else{
		return a[i].mydC;
	}
}
int whichb(int s,int i){
	if(s==1){
		return b[i].mydA;
	}else if(s==2){
		return b[i].mydB;
	}else{
		return b[i].mydC;
	}
}
struct node{
	bool isA,isB;
	int A,B,C;
}www[INF];
bool ccm(node rr,node tt){
	return rr.A>tt.A;
}
bool csp(node rr,node tt){
	return rr.B>tt.B;
}
bool cps(node rr,node tt){
	return rr.C>tt.C;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	int sub[3]={0};
	for(int k=1;k<=T;k++){
		cin>>n;
		
		for(int i=1;i<=n;i++){
			cin >> a[i].mydA >> a[i].mydB >> a[i].mydC;
			a[i].sum=a[i].mydA+a[i].mydB+a[i].mydC;
			b[i].mydA=a[i].mydA;b[i].mydB=a[i].mydB;b[i].mydC=a[i].mydC;
			b[i].sum=a[i].sum;
			www[i].A=a[i].mydA;www[i].B=a[i].mydB;www[i].C=a[i].mydC;
			www[i].isA=www[i].isB=0;
		}
		sort(a+1,a+1+n,cmp);
		sort(b+1,b+1+n,cmp1);
		int cnt=0,rnt=0;
		for(int i=1;i<=n;i++){
			int zuiai=ccz(a[i].mydA,a[i].mydB,a[i].mydC);
			if(sub[zuiai]>=n/2){
				int dierai=czz(a[i].mydA,a[i].mydB,a[i].mydC);
				if(sub[dierai]>=n/2){
					int disanai=6-zuiai-dierai;
					cnt+=whicha(disanai,i);
					sub[disanai]++;
				}else{
					sub[dierai]++;
					cnt+=whicha(dierai,i);
				}
			}else{
				sub[zuiai]++;
				cnt+=whicha(zuiai,i);
			}
		}
		
		sub[1]=sub[2]=sub[3]=0;
		/*for(int i=1;i<=n;i++){
			cout<<b[i].mydA<<" "<<b[i].mydB<<" "<<b[i].mydC<<endl;
		}*/
		for(int i=1;i<=n;i++){
			int zuibi=ccz(b[i].mydA,b[i].mydB,b[i].mydC);
			int dierbi=czz(b[i].mydA,b[i].mydB,b[i].mydC);
			int disbnbi=6-zuibi-dierbi;
//			cout<<zuibi<<" "<<dierbi<<" "<<disbnbi<<endl;
			if(sub[zuibi]>=n/2){
				if(sub[dierbi]>=n/2){
					rnt+=whichb(disbnbi,i);
					sub[disbnbi]++;
				}else{
					sub[dierbi]++;
					rnt+=whichb(dierbi,i);
				}
			}else{
				sub[zuibi]++;
				rnt+=whichb(zuibi,i);
			}
//			cout<<whichb(zuibi,i)<<" "<<whichb(dierbi,i)<<" "<<whichb(disbnbi,i)<<endl;
		}
		sort(www+1,www+1+n,ccm);
		int mst=0;
	/*	for(int i=1;i<=1;i++){
			for(int j=1;j<=n/2;j++){
				mst+=www[j].A;
				www[j].isA=1;
			} 
			sort(www+1,www+1+n,csp);
			for(int j=1,mer=1;mer<=n/2;j++){
				if(www[j].isA=1){
					continue;
				}else{
					mst+=www[j].B;
					mer++;
					www[j].isB=1;
				}
			} 
			sort(www+1,www+1+n,cps);
			for(int j=1,mer=1;mer<=n/2;j++){
				if(www[j].isB=1||www[j].isA==1){
					continue;
				}else{
					mst+=www[j].C;
					mer++;
				}
			} 
		}*/
		cout<<max(cnt,max(rnt,mst))<<endl;
		sub[1]=sub[2]=sub[3]=0;
	}
	return 0;
}
