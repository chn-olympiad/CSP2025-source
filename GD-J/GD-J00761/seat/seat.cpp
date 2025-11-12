#include<bits/stdc++.h>
using namespace std;
int wo_bu_zhi_dao[100],wo_bu_ming_bai,wo_gao_bu_dong,wo_yao_shang_chou_xiang_dai_ma_da_shang,bi_zhe_yan_jing_xie_de_bian_liang_ming;
int main(){
	//我的代码太难绷了 
	//笑了两个小时才写出来 
	//神秘变量名
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>wo_bu_ming_bai>>wo_gao_bu_dong;
	for(int i=0;i<wo_bu_ming_bai*wo_gao_bu_dong;i++){
		cin>>wo_bu_zhi_dao[i];
	}
	wo_yao_shang_chou_xiang_dai_ma_da_shang=wo_bu_zhi_dao[0];
	sort(wo_bu_zhi_dao,wo_bu_zhi_dao+wo_bu_ming_bai*wo_gao_bu_dong);
	bi_zhe_yan_jing_xie_de_bian_liang_ming=wo_bu_ming_bai*wo_gao_bu_dong-1;
	for(int i=0;i<wo_gao_bu_dong;i++){
		if(i%2==0){
			for(int j=0;j<wo_bu_ming_bai;j++){
				if(wo_bu_zhi_dao[bi_zhe_yan_jing_xie_de_bian_liang_ming]==wo_yao_shang_chou_xiang_dai_ma_da_shang){
					cout<<i+1<<' '<<j+1;
					goto IDK;
				}
				bi_zhe_yan_jing_xie_de_bian_liang_ming--;
			}
		}else{
			for(int j=wo_bu_ming_bai-1;j>=0;j--){
				if(wo_bu_zhi_dao[bi_zhe_yan_jing_xie_de_bian_liang_ming]==wo_yao_shang_chou_xiang_dai_ma_da_shang){
					cout<<i+1<<' '<<j+1;
					goto IDK;
				}
				bi_zhe_yan_jing_xie_de_bian_liang_ming--;
			}
		}
	}
	IDK:
		return 0;
}
