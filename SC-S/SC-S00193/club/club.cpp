#include<bits/stdc++.h>
using namespace std;

long long T, n, a[114514], b[114514], c[114514], ca, cb, cc, cn, num, ans, t[3];
bool isA=1, isB=1;

struct str{
	int cnt=0;
	int score=0;
	int low=0;
}A[114514], B[114514], C[114514], nn[114514];

bool cmp(str s1, str s2){
	return s1.score>s2.score;
}

bool cmp2(str s1, str s2){
	return s1.low>s2.low;
}

void init(str &s){
	s.cnt=0, s.score=0;
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin>>T;
	while(T--){
		ans=0, ca=0, cb=0, cc=0;
		cin>>n;
		num=n/2;
		if(n==2){
			for(int i=1;i<=n;i++) cin>>a[i]>>b[i]>>c[i];
			for(int i=1;i<=3;i++){
				for(int j=1;j<=3;j++){
					if(j==i) continue;
					long long g1, g2;
					if(i==1) g1=a[1];
					else if(i==2) g1=b[1];
					else if(i==3) g1=c[1];
					if(j==1) g2=a[2];
					else if(j==2) g2=b[2];
					else if(j==3) g2=c[2];
					ans=max(ans, g1+g2);
				}
			}
			cout<<ans<<endl;
			continue;
		}
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(b[i]!=0||c[i]!=0) isA=0;
			if(c[i]!=0) isB=0;
			nn[++cn].cnt=i;
			if(n<=num) nn[cn].low=b[i]-a[i];
			else nn[cn].low=a[i]-b[i];
			t[0]=a[i], t[1]=b[i], t[2]=c[i], sort(t, t+3);
			int temp=t[2];
			int j=2;
			bool sign=0;
			while(!sign){
				if(temp==a[i]){
					if(ca+1<=num) A[++ca].cnt=i, A[ca].score=temp, sign=1;
					else if(temp>A[ca].score) A[ca].cnt=i, A[ca].score=temp, sign=1;
					else if(temp<=A[ca].score) temp=t[--j];
					sort(A+1, A+1+ca, cmp);
				}
				if(temp==b[i]){
					if(cb+1<=num) B[++cb].cnt=i, B[cb].score=temp, sign=1;
					else if(temp>B[cb].score) B[cb].cnt=i, B[cb].score=temp, sign=1;
					else if(temp<=B[cb].score) temp=t[--j];
					sort(B+1, B+1+cb, cmp);
				}
				if(temp==c[i]){
					if(cc+1<=num) C[++cc].cnt=i, C[cc].score=temp, sign=1;
					else if(temp>C[cc].score) C[cc].cnt=i, C[cc].score=temp, sign=1;
					else if(temp<=C[cc].score) temp=t[--j];
					sort(C+1, C+1+cc, cmp);
				}
			}
		}
		if(!isA){
			for(int i=1;i<=num;i++){
//			cout<<A[i].score<<" "<<B[i].score<<" "<<C[i].score<<endl;
				ans+=A[i].score+B[i].score+C[i].score, init(A[i]), init(B[i]), init(C[i]);
//			cout<<A[i].score<<" "<<B[i].score<<" "<<C[i].score<<endl;
			}
			cout<<ans<<endl;
		}
		else if(isA){
			sort(a+1, a+1+n);
			for(int i=n;i>num;i--) ans+=a[i];
			for(int i=1;i<=num;i++) init(A[i]), init(B[i]), init(C[i]);
			cout<<ans<<endl;
		}
		else if(isB){
			sort(nn+1, nn+1+n, cmp2);
			for(int i=1;i<=n;i++){
				if(i<=num) ans+=a[i];
				else ans+=b[i];
			}
			for(int i=1;i<=num;i++){
				if(ans>=0) ans+=nn[i].low;
				else ans+=max((int)ans, 0);
			}
			for(int i=1;i<=num;i++) init(A[i]), init(B[i]), init(C[i]);
			cout<<ans<<endl;
		}
	} 
	return 0;
}