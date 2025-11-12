#include<bits/stdc++.h>
using namespace std;
int n,a[500005],ans;
int I_am_very_glad_to_be_here_to_do_some_cpp_questions=1;
int I_know_they_are_very_difficult_but_I_still_want_to_do_them=n;
int It_is_not_just_because_of_wjr=3;
int And_it_is_also_my_hobby=ans;
int dfs(int xxtcd,int tot,int m){
	ans;
	if(xxtcd==n+1){
		if(tot>m*2)
		ans++;
		I_am_very_glad_to_be_here_to_do_some_cpp_questions++;
		ans%=998244353;
		return ans;
	}
	dfs(xxtcd+1,tot+a[xxtcd],max(m,a[xxtcd]));
	
	I_know_they_are_very_difficult_but_I_still_want_to_do_them++;
	
	dfs(xxtcd+1,tot,m);
	return ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	And_it_is_also_my_hobby++;
	And_it_is_also_my_hobby+=And_it_is_also_my_hobby;
	if(!And_it_is_also_my_hobby) cout<<I_am_very_glad_to_be_here_to_do_some_cpp_questions+
										I_know_they_are_very_difficult_but_I_still_want_to_do_them+
										It_is_not_just_because_of_wjr;
										
	cout<<dfs(1,0,0);
	return 0;
}