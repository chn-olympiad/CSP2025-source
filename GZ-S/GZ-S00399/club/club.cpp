//GZ-S00399 贵阳市第一中学 薛子彦
#include<iostream>
#include<algorithm>
using namespace std;
int n,a[100010][4][3],bm[3][100010];
bool c[100010];
/*
struct idxd_int{
	int idx,data;
};
*/
//idx:原编号 data:数据区【名单】 
bool cmp(int x,int y){
	return a[a[x][2][2]][0]-a[a[x][1][2]][0]>a[a[y][2][2]][0]-a[a[y][1][2]][0];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		//a[i][j][0]:第i个成员对第j个部门的满意度 
		//a[i][j][1]:排序a[i][j][0]
		//a[i][j][2]:第i个成员满意度第j高的部门 
		int cnt[3]={0,0,0};
		//cout<<"Inputing:n\n";
		cin>>n;
		for(int i=1;i<=n;i++){
			//cout<<"Inputing:a_[i,#,0]\n";
			cin>>a[i][1][0]>>a[i][2][0]>>a[i][3][0];
			a[i][1][1]=a[i][1][0];
			a[i][2][1]=a[i][2][0];
			a[i][3][1]=a[i][3][0];
			a[i][1][2]=1;
			a[i][2][2]=2;
			a[i][3][2]=3;
			if(a[i][1][1]<a[i][2][1]){
				swap(a[i][1][1],a[i][2][1]);
				swap(a[i][1][2],a[i][2][2]);
			}
			if(a[i][2][1]<a[i][3][1]){
				swap(a[i][2][1],a[i][3][1]);
				swap(a[i][2][2],a[i][3][2]);
			}
			if(a[i][1][1]<a[i][2][1]){
				swap(a[i][1][1],a[i][2][1]);
				swap(a[i][1][2],a[i][2][2]);
			}
			bm[cnt[a[i][1][2]-1]++][a[i][1][2]]=i;
		}
		/*
		cout<<"Output:a_[i,#,#]\n";
		for(int i=1;i<=n;i++){
			cout<<a[i][1][0]<<' '<<a[i][2][0]<<' '<<a[i][3][0]<<' '
			<<a[i][1][1]<<' '<<a[i][2][1]<<' '<<a[i][3][1]<<' '
			<<a[i][1][2]<<' '<<a[i][2][2]<<' '<<a[i][3][2]<<endl;
		}
		cout<<"Output:cnt_#\n";
		cout<<cnt[0]<<' '<<cnt[1]<<' '<<cnt[2]<<endl;
		cout<<"Output:c_#\n";
		for(int i=1;i<=n;i++) cout<<c[i]<<' ';
		*/
		if(cnt[0]>n/2){
			sort(bm[0]+1,bm[0]+1+n,cmp);
			for(int i=cnt[0];i>n/2;i--){
				bm[cnt[a[i][2][2]-1]++][a[i][2][2]]=bm[0][i];
				cnt[0]--;
				c[i]=1;
			}
		}
		else if(cnt[1]>n/2){
			sort(bm[1]+1,bm[1]+1+n,cmp);
			for(int i=cnt[0];i>n/2;i--){
				bm[cnt[a[i][2][2]-1]++][a[i][2][2]]=bm[1][i];
				cnt[1]--;
				c[i]=1;
			}
		}
		else if(cnt[2]>n/2){
			sort(bm[2]+1,bm[2]+1+n,cmp);
			for(int i=cnt[0];i>n/2;i--){
				bm[cnt[a[i][2][2]-1]++][a[i][2][2]]=bm[2][i];
				cnt[2]--;
				c[i]=1;
			}
		}
		/*
		cout<<"Output:a_[i,#,#]\n";
		for(int i=1;i<=n;i++){
			cout<<a[i][1][0]<<' '<<a[i][2][0]<<' '<<a[i][3][0]<<' '
			<<a[i][1][1]<<' '<<a[i][2][1]<<' '<<a[i][3][1]<<' '
			<<a[i][1][2]<<' '<<a[i][2][2]<<' '<<a[i][3][2]<<endl;
		}
		cout<<"Output:cnt_#\n";
		cout<<cnt[0]<<' '<<cnt[1]<<' '<<cnt[2]<<endl;
		cout<<"Output:c_#\n";
		for(int i=1;i<=n;i++) cout<<c[i]<<' ';
		*/
		int sum=0;
		for(int i=1;i<=n;i++) sum+=a[i][a[i][1+c[i]][2]][0];
		//cout<<"Output:sum\n";
		cout<<sum<<endl;
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
2
10 9 8
4 0 0

*/

