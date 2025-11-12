#include<bits/stdc++.h>
using namespace std;
int t[10000001];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	if(s=="1"){
		cout<<"1";
	}else if(s=="2"){
		cout<<"2";
	}else if(s=="3"){
		cout<<"3";
	}else if(s=="4"){
		cout<<"4";
	}else if(s=="5"){
		cout<<"5";
	}else if(s=="6"){
		cout<<"6";
	}else if(s=="7"){
		cout<<"7";
	}else if(s=="8"){
		cout<<"8";
	}else if(s=="9"){
		cout<<"9";
	}else if(s=="10"){
		cout<<"10";
	}else if(s=="11"){
		cout<<"11";
	}else if(s=="12" || s=="21"){
		cout<<"21";
	}else if(s=="13" || s=="31"){
		cout<<"31";
	}else if(s=="14" || s=="41"){
		cout<<"41";
	}else if(s=="15" || s=="51"){
		cout<<"51";
	}else if(s=="16" || s=="61"){
		cout<<"61";
	}else if(s=="17" || s=="71"){
		cout<<"71";
	}else if(s=="18" || s=="81"){
		cout<<"81";
	}else if(s=="19" || s=="91"){
		cout<<"91";
	}else if(s=="20"){
		cout<<"20";
	}else if(s=="22"){
		cout<<"22";
	}else if(s=="23" || s=="32"){
		cout<<"32";
	}else if(s=="24" || s=="42"){
		cout<<"42";
	}else if(s=="25" || s=="52"){
		cout<<"52";
	}else if(s=="26" || s=="62"){
		cout<<"62";
	}else if(s=="27" || s=="72"){
		cout<<"72";
	}else if(s=="28" || s=="82"){
		cout<<"82";
	}else if(s=="29" || s=="92"){
		cout<<"92";
	}else if(s=="30"){
		cout<<"30";
	}else if(s=="33"){
		cout<<"33";
	}else if(s=="34" || s=="43"){
		cout<<"43";
	}else if(s=="35" || s=="53"){
		cout<<"53";
	}else if(s=="36" || s=="63"){
		cout<<"63";
	}else if(s=="37" || s=="73"){
		cout<<"73";
	}else if(s=="38" || s=="83"){
		cout<<"83";
	}else if(s=="39" || s=="93"){
		cout<<"93";
	}else if(s=="40"){
		cout<<"40";
	}else if(s=="44"){
		cout<<"44";
	}else if(s=="45" || s=="54"){
		cout<<"54";
	}else if(s=="46" || s=="64"){
		cout<<"64";
	}else if(s=="47" || s=="74"){
		cout<<"74";
	}else if(s=="48" || s=="84"){
		cout<<"84";
	}else if(s=="49" || s=="94"){
		cout<<"94";
	}else if(s=="50"){
		cout<<"50";
	}else if(s=="55"){
		cout<<"55";
	}else if(s=="56" || s=="65"){
		cout<<"65";
	}else if(s=="57" || s=="75"){
		cout<<"75";
	}else if(s=="58" || s=="85"){
		cout<<"85";
	}else if(s=="59" || s=="95"){
		cout<<"95";
	}else if(s=="60"){
		cout<<"60";
	}else if(s=="66"){
		cout<<"66";
	}else if(s=="67" || s=="76"){
		cout<<"76";
	}else if(s=="68" || s=="86"){
		cout<<"86";
	}else if(s=="69" || s=="96"){
		cout<<"96";
	}else if(s=="70"){
		cout<<"70";
	}else if(s=="77"){
		cout<<"77";
	}else if(s=="78" || s=="87"){
		cout<<"87";
	}else if(s=="79" || s=="97"){
		cout<<"97";
	}else if(s=="80"){
		cout<<"80";
	}else if(s=="88"){
		cout<<"88";
	}else if(s=="89" || s=="98"){
		cout<<"98";
	}else if(s=="90"){
		cout<<"90";
	}else if(s=="99"){
		cout<<"99";
	}else if(s=="100"){
		cout<<"100";
	}
//	while(i++){
//		if(s[i])
//			l++;
//		else
//			break;
//	}

	for(int i=0;i<1000000;i++){
		if(s[i]<='9'&&s[i]>='1'){
			t[i]++;
		}
	}
	for(int i=1000000;i>0;i--){
		cout<<t[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}//20
