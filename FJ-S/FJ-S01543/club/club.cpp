#include<bits/stdc++.h>
using namespace std;
int t,n,a[100001][11],sum=0,cl[11][2];
int pdcl(){
	if (cl[1][0]<=n/2&&cl[2][0]<=n/2&&cl[3][0]<=n/2) return -114514;
	else return (cl[1][0]>n/2?1:(cl[2][0]>n/2?2:3));
}
void baoli(int cl1,int cl2,int cl3,int s,int x){
	//baoli(114514,1919810,114514);
	if (x==n+1){
		sum=max(sum,s);
		return;
	}
	if (cl1+1<=n/2) baoli(cl1+1,cl2,cl3,s+a[x][1],x+1);
	if (cl2+1<=n/2) baoli(cl1,cl2+1,cl3,s+a[x][2],x+1);
	if (cl3+1<=n/2) baoli(cl1,cl2,cl3+1,s+a[x][3],x+1);
}
//O(3^n)
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while (t--){
		cin>>n;
		for (int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			a[i][4]=max(max(a[i][1],a[i][2]),a[i][3]);
			for (int j=1;j<=3;j++) if (a[i][j]>a[i][6]) a[i][5]=j,a[i][6]=a[i][j];
			//bbb what did i write?
			cl[a[i][5]][0]++;
			cl[a[i][5]][1]+=a[i][4];
			sum+=a[i][4];
		}
		//ke du xing ji ()
		if (pdcl()==-114514){
			cout<<sum<<endl;
			sum=0;
		}else{
			sum=0;
			//cout<<"No,Sir!"<<endl;
			baoli(0,0,0,0,1);
			cout<<sum<<endl;
			//eeeeeaaaaa wo de di pai@!@!@@@@!#####@#$
		}
		//O(t*3^n)
		//log3(100000000)=16~17;
		//QAQ
		//max 80pts
		//min 0pts(
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//zao gao -J T1 xie le 9610 hai you jiu ma
//if (this_year.s_pts>=100){eat 1145141919810114514t chocolates or more;}
