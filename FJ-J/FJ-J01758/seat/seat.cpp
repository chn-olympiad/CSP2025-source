#include<bits/stdc++.h>
using namespace std;
int n,m,a[201],rp;
bool awa(int aa,int bb){
	return aa>bb;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>rp;
	a[1]=rp;
	for (int i=2;i<=n*m;i++) cin>>a[i];
	sort(a+1,a+n*m+1,awa);
	for (int i=1;i<=n*m;i++){
		//cout<<a[i]<<" ";
		if (rp==a[i]){
			rp=i;
			break;
		}
	}
	//cout<<rp;
	cout<<ceil(1.0*rp/n)<<" "<<((int)ceil(1.0*rp/n)%2==1?(rp-1)%n+1:n-(rp-1)%n);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//1 4 5
//2 3 6
//xiao huo zhi shi zai ke ting tiao le yi duan wu dao
//jiu bei guan jia huo huo da duan le shang tui
//awa awa awa awa awa awa awa awa awa awa awa awa awa awa awa awa awa awa awa awa awa awa awa awa awa awa awa awa awa awa awa awa awa awa awa awa awa awa awa awa awa awa awa awa
//wo xiang shang csp-j FJ chou ciang dai ma da shang QAQ WAW qiu qiu le
//wei reomtejudge mo ai QAQ QAQ
//rua~~~~~~~~~~~~~~~ sha lu guang huan~~~~~~~~~~~~~~~~~~~~~~
